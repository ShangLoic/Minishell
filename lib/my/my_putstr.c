/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** task02
*/
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}
