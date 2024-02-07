/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The load_game.c
*/

#include "../include/navy.h"

static void change_signal_by_zero(int signal)
{
    game.signal = 0;
}

static void change_signal_by_one(int signal)
{
    game.signal = 1;
}

void player_one(void)
{
    char *position = get_position();

    send_attack(game.pid, position);
    if (get_win())
        return;
    write(1, "waiting for enemy's attack...\n", 30);
    received_attack();
    if (send_win())
        return;
    display_state();
}

void player_two(void)
{
    char *position;

    write(1, "waiting for enemy's attack...\n", 30);
    received_attack();
    if (send_win())
        return;
    position = get_position();
    send_attack(game.pid, position);
    if (get_win())
        return;
    display_state();
}

int load_game(void)
{
    game.signal = -1;
    display_state();
    signal(SIGUSR1, &change_signal_by_zero);
    signal(SIGUSR2, &change_signal_by_one);
    while (game.end == 0) {
        if (game.player == 0)
            player_one();
        else
            player_two();
    }
    my_free();
    return game.end - 1;
}
