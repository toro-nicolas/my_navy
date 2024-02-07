/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The print_map.c
*/

#include "../include/navy.h"

void print_case(char *str, int index)
{
    write(1, &str[index], 1);
    if (str[index + 1] != '\0')
        write(1, " ", 1);
    else
        write(1, "\n", 1);
}

void print_map(char **map)
{
    write(1, " |A B C D E F G H\n-+---------------\n", 36);
    for (int index = 0; map[index] != NULL; index++) {
        my_putchar(index + '1');
        write(1, "|", 1);
        for (int index_str = 0; map[index][index_str] != '\0'; index_str++)
            print_case(map[index], index_str);
    }
}

void display_state(void)
{
    write(1, "my positions:\n", 14);
    print_map(game.player_map);
    write(1, "enemy's positions:\n", 19);
    print_map(game.enemy_map);
}
