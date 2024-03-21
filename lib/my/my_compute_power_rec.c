/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** task04
*/
#include <unistd.h>
#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

        if (p >= 2){
            p--;
            result = nb * (my_compute_power_rec(nb, p));
            return result;
        }
        if (p == 1) {
            return nb;
        }
        if (p == 0) {
            return 1;
        } else {
            return 0;
        }
}
