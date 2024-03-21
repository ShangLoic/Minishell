/*
** EPITECH PROJECT, 2023
** int_to_str
** File description:
** ra
*/
#include <stdio.h>
#include <stdlib.h>

char *int_to_str(int num)
{
    int i;
    int rem;
    int len = 0;
    int n = num;
    char *str = malloc(sizeof(char) * 100);

    for (; n != 0; len++) {
        n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return str;
}
