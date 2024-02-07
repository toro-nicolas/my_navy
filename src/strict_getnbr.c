/*
** EPITECH PROJECT, 2024
** navy
** File description:
** The strict_getnbr.c
*/

int strict_getnbr(char *number)
{
    int nb = 0;

    if (number[0] == '\0')
        return -1;
    for (int index = 0; number[index] != '\0'; index++) {
        if (number[index] < '0' || number[index] > '9')
            return -1;
        else
            nb = nb * 10 + (number[index] - 48);
    }
    return nb;
}
