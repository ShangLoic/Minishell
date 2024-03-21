/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** library
*/

float my_getnbr(char const *str)
{
    int i = 0;
    int ng = 1;
    float nb = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            ng *= -1;
                }
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    nb = nb * ng;
    return nb;
}
