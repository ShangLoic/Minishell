/*
** EPITECH PROJECT, 2024
** printf
** File description:
** bttf
*/

#include <stdio.h>
#include <stdbool.h>
#include "my.h"

void le_e(char e)
{
    if (e == 'e') {
        my_putchar('e');
    } else {
        my_putchar('E');
    }
}

int counti(int count)
{
    if (count >= 0) {
        my_putchar('+');
    } else {
        count *= -1;
        my_putchar('-');
    }
    if (count < 10 || count > -10) {
        my_putchar('0');
    }
    my_put_nbr(count);
}

int my_put_expoo(double f, int i, char e, int a)
{
    int count = 0;

    if (f < 0) {
        my_putchar('-');
        f *= -1;
    }
    while (f < 1) {
        count--;
        f *= 10;
    }
    while (f >= 10) {
        count++;
        f /= 10;
    }
    my_put_flt(f, a);
    le_e(e);
    counti(count);
    return 0;
}
