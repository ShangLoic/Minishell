/*
** EPITECH PROJECT, 2024
** useful2
** File description:
** azfegz3
*/

#include "my.h"

int number_of_arg(char *str, char separator)
{
    int count = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == separator)
            count++;
    }
    return count;
}

char *search_str_in_array(char **array, char *str)
{
    int count = 0;
    int y = 0;
    int x = 0;
    char *copy;

    for (; array[y] != NULL; y++) {
        for (; str[x] != '\0' && str[x] == array[y][x]; x++) {
            count++;
        }
        if (count == my_strlen(str))
            break;
        x = 0;
        count = 0;
    }
    copy = malloc(sizeof(char) * (my_strlen(array[y]) - my_strlen(str)) + 1);
    for (int i = 0; array[y][x] != '\0'; x++) {
        copy[i] = array[y][x];
        i++;
    }
    return copy;
}

int search_line_in_array(char **array, char *str)
{
    int count = 0;
    int y = 0;
    int x = 0;

    for (; array[y] != NULL; y++) {
        for (; str[x] != '\0' && str[x] == array[y][x]; x++) {
            count++;
        }
        if (count == my_strlen(str))
            return y;
        x = 0;
        count = 0;
    }
    return -1;
}

char *my_get_selected_str(char **array, char *str, char separator, int nb)
{
    int count = 0;
    int x = my_strlen(str);
    char *copy;
    int len = 0;
    int y = search_line_in_array(array, str);

    for (int count = 0; count != nb; count++) {
        for (; array[y][x] != separator && array[y][x] != '\0'; x++) {
        }
        x++;
    }
    for (; array[y][x + len] != separator &&
    array[y][x + len] != '\0'; len++) {
    }
    copy = malloc(sizeof(char) * len + 1);
    for (int i = 0; array[y][x] != separator && array[y][x] != '\0'; x++) {
        copy[i] = array[y][x];
        i++;
    }
    return copy;
}

int count_nb_of_cmd(char *str)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}
