/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The main.c
*/

#include "../include/navy.h"

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n"
            "DESCRIPTION\n\tfirst_player_pid: only for the 2nd player."
            " pid of the first player.\n\tnavy_positions:"
            "file representing the positions of the ships.\n");
        return 0;
    }
    if (argc == 2)
        return load_player_one(argv);
    if (argc == 3)
        return load_player_two(argv);
}
