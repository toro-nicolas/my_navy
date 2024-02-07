/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The check_win.c
*/

#include "../include/navy.h"

int check_position_on_boat(char *position)
{
    if (game.player_map[position[1] - '1'][position[0] - 'A'] != '.')
        return 1;
    return 0;
}

static int check_colonnes(char *map)
{
    for (int col = 0; col < 8; col++)
        if (map[col] != '.' && map[col] != 'x' && map[col] != 'o')
            return 0;
    return 1;
}

static int check_map_end(char **map)
{
    for (int line = 0; line < 8; line++)
        if (check_colonnes(map[line]) == 0)
            return 0;
    return 1;
}

int send_win(void)
{
    while (game.signal == -1);
    if (check_map_end(game.player_map)) {
        game.end = 2;
        display_state();
        write(1, "Enemy won\n", 10);
        kill(game.pid, SIGUSR2);
        return 1;
    }
    kill(game.pid, SIGUSR1);
    while (game.signal == -1);
    return 0;
}

int get_win(void)
{
    game.signal = -1;
    while (game.signal == -1);
    if (game.signal == 1) {
        game.end = 1;
        display_state();
        write(1, "I won\n", 6);
        return 1;
    }
    game.signal = -1;
    kill(game.pid, SIGUSR2);
    return 0;
}
