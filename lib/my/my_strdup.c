/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Workshop
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *a)
{
    char *b = malloc(sizeof(char) * my_strlen(a) + 1);

    for (int i = 0; i < my_strlen(a); i++) {
        b[i] = a[i];
    }
    b[my_strlen(a) + 1] = '\0';
    return b;
}
