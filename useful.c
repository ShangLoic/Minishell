/*
** EPITECH PROJECT, 2024
** efz
** File description:
** ezfgre
*/

#include "my.h"

int getstr(char *str, int space)
{
    int i = 0;
    int count = 0;
    int nb = 0;

    while (i < space) {
        if (str[count] == ' ') {
            i++;
        }
        count++;
    }
    i = 0;
    while (str[count] != ' ' && str[count] != '\0') {
        i++;
        count++;
    }
    return i;
}

int count_line(char *a)
{
    int i = 0;
    int line = 0;

    while (a[i] != '\0') {
        if (a[i] == ' ') {
            line++;
        }
        i++;
    }
    return line;
}

char **str_to_array(char *str)
{
    int xbis = 0;
    int x = 0;
    char **map = malloc(sizeof(char *) * count_line(str) + 1);

    for (int i = 0; i <= count_line(str); i++) {
        if (i == 0)
            map[i] = malloc(sizeof(char) * getstr(str, i) + 6);
        else
            map[i] = malloc(sizeof(char) * getstr(str, i) + 1);
    }
    for (int y = 0; y <= count_line(str); y++) {
        for (xbis = 0; str[x] != '\0' && str[x] != ' '; x++) {
            map[y][xbis] = str[x];
            xbis++;
        }
        x++;
        map[y][xbis] = '\0';
    }
    map[count_line(str) + 1] = NULL;
    return map;
}

char *my_strclean_assign(char *str, int len, int k)
{
    int j = 0;
    char *copy;

    copy = malloc(sizeof(char) * len + 1);
    for (int i = 0; str[k] != '\0'; k++) {
        for (j = k; str[j] == ' ' || str[j] == '\t'; j++) {
        }
        if (j != k) {
            k = j;
            copy[i] = ' ';
            i++;
        }
        copy[i] = str[k];
        i++;
    }
    return copy;
}

char *my_strclean(char *str)
{
    char *copy;
    int len = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' || str[i + 1] != ' ')
            len++;
    }
    while (str[k] == ' ' || str[k] == '\t')
        k++;
    copy = my_strclean_assign(str, len, k);
    for (int i = my_strlen(copy) - 1; copy[i] == ' ' || copy[i] == '\n'; i--)
        copy[i] = '\0';
    return copy;
}
