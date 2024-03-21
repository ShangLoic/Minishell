/*
** EPITECH PROJECT, 2023
** my_compute_power
** File description:
** my_compute_power
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0') {
        a++;
    }
    while (nb != 0) {
        dest[a + b] = src[b];
        b++;
        nb--;
    }
    return dest;
}
