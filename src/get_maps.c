/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The get_map.c
*/

#include "../include/navy.h"

char **get_empty_map(void)
{
    char **map = my_calloc(sizeof(char *), 9, 1);

    for (int index = 0; index < 8; index++) {
        map[index] = my_calloc(sizeof(char), 9, 1);
        for (int j = 0; j < 8; j++)
            map[index][j] = '.';
        map[index][8] = '\0';
    }
    map[8] = NULL;
    return map;
}

void edit_place(char **coordinates, int *map_info, int len)
{
    if (coordinates[map_info[2] * 3 + 1][0] ==
    coordinates[map_info[2] * 3 + 2][0])
        game.player_map[map_info[0] + len][map_info[1]] =
            coordinates[map_info[2] * 3][0];
    else
        game.player_map[map_info[0]][map_info[1] + len] =
            coordinates[map_info[2] * 3][0];
}

void set_map(char **coordinates)
{
    int start_x = 0;
    int start_y = 0;
    int map_info[4];

    for (int lines = 0; lines < 4; lines++) {
        if (coordinates[lines * 3 + 1][0] < coordinates[lines * 3 + 2][0])
            start_y = coordinates[lines * 3 + 1][0] - 'A';
        else
            start_y = coordinates[lines * 3 + 2][0] - 'A';
        if (coordinates[lines * 3 + 1][1] < coordinates[lines * 3 + 2][1])
            start_x = coordinates[lines * 3 + 1][1] - '1';
        else
            start_x = coordinates[lines * 3 + 2][1] - '1';
        map_info[0] = start_x;
        map_info[1] = start_y;
        map_info[2] = lines;
        for (int len = 0; len < coordinates[lines * 3][0] - '0'; len++)
            edit_place(coordinates, map_info, len);
    }
}

static void free_word_array(char **array)
{
    for (int index = 0; array[index] != NULL; index++)
        free(array[index]);
    free(array);
}

int check_map(char *map)
{
    char **coordinates = my_str_to_word_array(map);

    if (search_error(coordinates))
        return 84;
    set_map(coordinates);
    free_word_array(coordinates);
    return 0;
}

int get_maps(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = my_calloc(sizeof(char), 33, 1);

    if (fd == -1)
        return 84;
    if (read(fd, buffer, 33) != 32)
        return 84;
    buffer[32] = '\0';
    game.player_map = get_empty_map();
    game.enemy_map = get_empty_map();
    return check_map(buffer);
}
