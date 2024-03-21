/*
** EPITECH PROJECT, 2024
** efz
** File description:
** ezfgre
*/

#include "my.h"

int nbrget(char *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] >= 48 && str[i] <= 57) {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    return nb;
}
