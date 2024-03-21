/*
** EPITECH PROJECT, 2024
** printf
** File description:
** bttf
*/

#include "my.h"

int aff(int entier, int dot, double number, int nb)
{
    if (nb == 0 && number >= 5) {
        entier++;
    }
    my_put_nbr(entier);
    if (nb == dot && dot >= 1) {
        my_putchar('.');
    }
    return 0;
}

void float_disp(int entier, int dot, double number, int nb)
{
    while (nb != 0) {
        entier = number;
        number = (number - entier) * 10;
        if (number > 9) {
            number = 0;
            entier++;
        }
        nb--;
        aff(entier, dot, number, nb);
    }
}

void my_put_flt(double number, int nb)
{
    int entier;
    int dot = nb;

    if (nb == -1) {
        dot = 6;
        nb = 6;
    }
    if (number < 0) {
        my_putchar('-');
        number *= -1;
    }
    nb++;
    float_disp(entier, dot, number, nb);
}
