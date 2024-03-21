/*
** EPITECH PROJECT, 2023
** my_compute_power
** File description:
** my_compute_power
*/
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;
    char *str = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    while (dest[a] != '\0') {
        str[a] = dest[a];
        a++;
    }
    while (src[b] != '\0') {
        str[a + b] = src[b];
        b++;
    }
    return str;
}
