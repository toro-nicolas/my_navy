/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The send_signal.c
*/

#include "../include/navy.h"

static int print_attack_status(char *position, int status)
{
    write(1, position, 2);
    if (status)
        write(1, ": hit\n", 6);
    else
        write(1, ": missed\n", 9);
}

void send_attack_status(char *position)
{
    char *new_position = transform_to_ascii(position);
    int status = check_position_on_boat(new_position);

    if (game.player_map[new_position[1] - '1'][new_position[0] - 'A'] == 'x') {
        print_attack_status(new_position, 0);
        kill(game.pid, SIGUSR2);
        return;
    }
    if (status) {
        game.player_map[new_position[1] - '1'][new_position[0] - 'A'] = 'x';
        print_attack_status(new_position, 1);
        kill(game.pid, SIGUSR2);
    } else {
        game.player_map[new_position[1] - '1'][new_position[0] - 'A'] = 'o';
        print_attack_status(new_position, 0);
        kill(game.pid, SIGUSR1);
    }
}

void get_attack_status(char *position)
{
    if (game.enemy_map[position[1] - '1'][position[0] - 'A'] == 'x') {
        print_attack_status(position, 0);
        kill(game.pid, SIGUSR2);
        return;
    }
    if (game.signal) {
        game.enemy_map[position[1] - '1'][position[0] - 'A'] = 'x';
        print_attack_status(position, 1);
    } else {
        game.enemy_map[position[1] - '1'][position[0] - 'A'] = 'o';
        print_attack_status(position, 0);
    }
    game.signal = -1;
    kill(game.pid, SIGUSR2);
}

void received_attack(void)
{
    char *position = my_calloc(sizeof(char), 9, 1);
    char *new_position;
    int status = 0;

    for (int index = 0; index < 8; index++) {
        while (game.signal == -1);
        position[index] = '0' + game.signal;
        game.signal = -1;
        kill(game.pid, SIGUSR2);
    }
    while (game.signal == -1);
    game.signal = -1;
    position[8] = '\0';
    send_attack_status(position);
}

void send_attack(int pid, char *position)
{
    char *new_position = transform_to_bits(position);

    game.signal = -1;
    for (int index = 0; index < 8; index++) {
        if (new_position[index] == '0')
            kill(pid, SIGUSR1);
        if (new_position[index] == '1')
            kill(pid, SIGUSR2);
        while (game.signal == -1);
        game.signal = -1;
    }
    kill(pid, SIGUSR2);
    while (game.signal == -1);
    get_attack_status(position);
}
