/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** task04
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int i)
{
    if (i < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
