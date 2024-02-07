/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The navy.h
*/

#include <fcntl.h>
#include <signal.h>
#include "mymemory.h"

#ifndef NAVY_H_
    #define NAVY_H_

typedef struct game_s {
    int player;
    int pid;
    char **player_map;
    char **enemy_map;
    int signal;
    int end;
} game_t;

extern game_t game;

int strict_getnbr(char *number);
int search_error(char **coordinates);
int get_maps(char *filepath);
void print_map(char **map);
char *get_position(void);
char *transform_to_bits(char *position);
char *transform_to_ascii(char *position);
int check_position_on_boat(char *position);
void send_attack(int pid, char *position);
void received_attack(void);
int load_player_one(char **argv);
int load_player_two(char **argv);
void display_state(void);
int send_win(void);
int get_win(void);
int load_game(void);

#endif /* NAVY_H_ */
