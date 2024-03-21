/*
** EPITECH PROJECT, 2024
** printf
** File description:
** bttf
*/

#include "my.h"

void base_display(int divised, bool maj)
{
    char *minu = "0123456789abcdef";
    char *manu = "0123456789ABCDEF";

    if (maj) {
        my_putchar(manu[divised]);
    } else {
        my_putchar(minu[divised]);
    }
}

int base_converter(long long number, int base, bool maj, int nb)
{
    long double copy = number;
    int i = 0;

    for (; copy >= base; i++) {
        copy /= base;
    }
    for (; nb > i + 1; nb--) {
        my_putchar('0');
    }
    for (int divised = 0; i >= 0; i--) {
        number = copy;
        divised = number % base;
        base_display(divised, maj);
        copy *= base;
    }
    return 0;
}

int my_putlong(long long nb)
{
    if (nb > 2147483648) {
        nb -= (2 *(nb - 0x80000000));
        nb *= -1;
    }
    if (nb == 2147483648)
        nb *= -1;
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
    return 0;
}
