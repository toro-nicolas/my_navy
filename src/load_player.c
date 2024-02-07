/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The load_player.c
*/

#include "../include/navy.h"

game_t game;

void print_pid(void)
{
    my_printf("my pid: %d\n", getpid());
}

void get_infos(int signal, siginfo_t *infos, void *context)
{
    if (signal == SIGUSR1 || signal == SIGUSR2)
        game.pid = infos->si_pid;
}

int load_player_one(char **argv)
{
    int map_status = get_maps(argv[1]);
    struct sigaction action;

    if (map_status == 84)
        return my_putstr_error("Invalid map !\n");
    game.player = 0;
    print_pid();
    write(1, "waiting for enemy connection...\n", 32);
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = &get_infos;
    sigaction(SIGUSR2, &action, NULL);
    pause();
    kill(game.pid, SIGUSR1);
    write(1, "enemy connected\n", 16);
    return load_game();
}

int load_player_two(char **argv)
{
    int map_status = get_maps(argv[2]);
    int player_one_pid = strict_getnbr(argv[1]);
    struct sigaction action;

    if (map_status == 84)
        return my_putstr_error("Invalid map !\n");
    if (player_one_pid < 0)
        return my_putstr_error("Invalid PID !\n");
    print_pid();
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = &get_infos;
    sigaction(SIGUSR1, &action, NULL);
    if (kill(my_getnbr(argv[1]), SIGUSR2) == -1)
        return my_putstr_error("Can't connect to the PID !\n");
    pause();
    game.player = 1;
    write(1, "successfully connected\n", 23);
    return load_game();
}
