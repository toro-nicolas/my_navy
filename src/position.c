/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The position.c
*/

#include "../include/navy.h"

char *get_position(void)
{
    char *input = my_calloc(sizeof(char), 1000, 1);

    while (input == NULL || input[0] < 'A' || input[0] > 'H' || input[1] < '1'
    || input[1] > '8' || input[2] != '\0') {
        input[2] = '\0';
        write(1, "attack: ", 8);
        read(0, input, 1000);
        if (input[0] >= 'A' && input[0] <= 'H' &&
        input[1] >= '1' && input[1] <= '8' &&
        (input[2] == '\0' || input[2] == '\n')) {
            input[2] = '\0';
            break;
        }
        write(1, "wrong position\n", 15);
    }
    return input;
}

static char *get_empty_position(void)
{
    char *position = my_calloc(sizeof(char), 9, 1);

    for (int index = 0; index < 8; index++)
        position[index] = '0';
    return position;
}

static char *get_letter(const char *position)
{
    char *letter = my_calloc(sizeof(char), 2, 1);
    char *letter_str;

    letter[0] = position[0] - 'A' + '0';
    letter[1] = '\0';
    letter_str = my_convert_base(letter, "0123456789", "01");
    my_revstr(letter_str);
    return letter_str;
}

static char *get_number(const char *position)
{
    char *number = my_calloc(sizeof(char), 2, 1);
    char *number_str;

    number[0] = position[1];
    number[1] = '\0';
    number_str = my_convert_base(number, "0123456789", "01");
    my_revstr(number_str);
    return number_str;
}

char *transform_to_bits(char *position)
{
    char *new_position = get_empty_position();
    char *letter_str = get_letter(position);
    char *number_str = get_number(position);

    for (int index = 3; index > -1 && letter_str[3 - index] != '\0'; index--)
        new_position[index] = letter_str[3 - index];
    for (int index = 7; index > 3 && number_str[7 - index] != '\0'; index--)
        new_position[index] = number_str[7 - index];
    return new_position;
}

char *transform_to_ascii(char *position)
{
    char *new_position = my_calloc(sizeof(char), 3, 1);
    int letter = (position[0] - '0') * 2 * 2 * 2 + (position[1] - '0') * 2 * 2
    + (position[2] - '0') * 2 + (position[3] - '0');
    int number = (position[4] - '0') * 2 * 2 * 2 + (position[5] - '0') * 2 * 2
    + (position[6] - '0') * 2 + (position[7] - '0');

    new_position[0] = letter + 'A';
    new_position[1] = number + '0';
    new_position[2] = '\0';
    return new_position;
}
