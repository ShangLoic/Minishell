/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** task01
*/
#include <unistd.h>

void my_swap(char **a, char **b)
{
    char *c = *a;

    *a = *b;
    *b = c;
}
