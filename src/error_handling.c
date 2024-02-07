/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The error_handling.c
*/

#include "../include/navy.h"

static int check_valid_characters(char **coordinates)
{
    for (int lines = 0; lines < 4; lines++) {
        if (coordinates[lines * 3][0] < '2' ||
        coordinates[lines * 3][0] > '5' ||
        coordinates[lines * 3 + 1][0] < 'A' ||
        coordinates[lines * 3 + 1][0] > 'H' ||
        coordinates[lines * 3 + 1][1] < '1' ||
        coordinates[lines * 3 + 1][1] > '8' ||
        coordinates[lines * 3 + 2][0] < 'A' ||
        coordinates[lines * 3 + 2][0] > 'H' ||
        coordinates[lines * 3 + 2][1] < '1' ||
        coordinates[lines * 3 + 2][1] > '8')
            return 1;
    }
    return 0;
}

static int check_equal_coordinates(char **coordinates)
{
    for (int lines = 0; lines < 4; lines++) {
        if (coordinates[lines * 3 + 1][0] == coordinates[lines * 3 + 2][0] &&
        coordinates[lines * 3 + 1][1] == coordinates[lines * 3 + 2][1])
            return 1;
    }
    return 0;
}

static int check_diagonal(char **coordinates)
{
    for (int lines = 0; lines < 4; lines++) {
        if (coordinates[lines * 3 + 1][0] != coordinates[lines * 3 + 2][0] &&
        coordinates[lines * 3 + 1][1] != coordinates[lines * 3 + 2][1])
            return 1;
    }
    return 0;
}

static int check_boat_size(char **coordinates)
{
    int size = 1;

    for (int lines = 0; lines < 4; lines++) {
        size = size + ABS((coordinates[lines * 3 + 1][0] -
        coordinates[lines * 3 + 2][0]));
        size = size + ABS((coordinates[lines * 3 + 1][1] -
        coordinates[lines * 3 + 2][1]));
        if (size != coordinates[lines * 3][0] - '0')
            return 1;
        size = 1;
    }
    return 0;
}

static int check_double_boat(char **coordinates)
{
    if (coordinates[0][0] == coordinates[3][0] || coordinates[0][0] ==
    coordinates[6][0] || coordinates[0][0] == coordinates[9][0] ||
    coordinates[3][0] == coordinates[6][0] || coordinates[3][0] ==
    coordinates[9][0] || coordinates[6][0] == coordinates[9][0])
        return 1;
    return 0;
}

int search_error(char **coordinates)
{
    if (check_valid_characters(coordinates))
        return 1;
    if (check_equal_coordinates(coordinates))
        return 1;
    if (check_diagonal(coordinates))
        return 1;
    if (check_boat_size(coordinates))
        return 1;
    if (check_double_boat(coordinates))
        return 1;
    return 0;
}
