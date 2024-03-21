/*
** EPITECH PROJECT, 2023
** my_compute_power
** File description:
** my_compute_power
*/

#include <stdio.h>

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (i != n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
