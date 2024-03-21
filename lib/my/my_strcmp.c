/*
** EPITECH PROJECT, 2023
** my_compute_power
** File description:
** my_compute_power
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2)) {
        return 84;
    }
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            return 84;
        }
    }
    return (0);
}
