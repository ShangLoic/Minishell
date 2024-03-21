/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/
#include "my.h"

int my_put_num(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_num(-nb);
    } else if (nb > 9) {
        my_put_num(nb / 10);
        my_put_num(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
    return 0;
}
