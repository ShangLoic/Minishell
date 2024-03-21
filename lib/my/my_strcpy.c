/*
** EPITECH PROJECT, 2023
** my_compute_power
** File description:
** my_compute_power
*/

int my_strcpy(char *a, char *b)
{
    int j;

    for (j = 0; b[j] != '\0'; j++) {
        a[j] = b[j];
    }
    a[j] = '\0';
    return 0;
}
