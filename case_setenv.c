/*
** EPITECH PROJECT, 2024
** efzgr
** File description:
** grehdgn
*/

#include "my.h"

input_s setenv_add(input_s input)
{
    int i = 0;

    while (input.ev[i] != NULL)
        i++;
    if (input.array[2] == NULL) {
        input.array[2] = "\0";
    }
    input.ev[i] = my_strcat(my_strcat(input.array[1], "="), input.array[2]);
    input.ev[i + 1] = NULL;
    return input;
}

input_s setenv_replace(input_s input)
{
    int i = 0;

    while (input.ev[i] != NULL)
        i++;
    if (search_line_in_array(input.ev, input.array[1]) != -1 &&
    input.array[2] != NULL) {
        input.ev[i] = my_strcat(my_strcat(input.array[1], "="),
        input.array[2]);
        my_swap(&input.ev[i], &input.ev[search_line_in_array(input.ev,
        my_strcat(input.array[1], "="))]);
        input.ev[i] = NULL;
    } else if (search_line_in_array(input.ev, input.array[1]) != -1) {
        input.ev[search_line_in_array(input.ev, my_strcat(input.array[1],
        "="))] = my_strcat(input.array[1], "=");
    } else
        input = setenv_add(input);
    return input;
}

input_s setenv_error_handling(input_s input, int count)
{
    for (int i = 0; input.array[1][i] != '\0'; i++) {
        if (!(input.array[1][i] >= 45 && input.array[1][i] <= 57)
        && !(input.array[1][i] >= 65 && input.array[1][i] <= 90)
        && !(input.array[1][i] >= 97 && input.array[1][i] <= 122)
        && input.array[1][i] != ' ' && input.array[1][i] != '/'
        && input.array[1][i] != '_'){
            my_printf("setenv: Variable name must contain alphanumeric ");
            my_printf("characters.\n");
            exit(1);
        }
    }
    if (count > 3) {
        my_printf("setenv: Too many arguments.\n");
        exit(1);
    }
    if (count >= 2){
        input = setenv_replace(input);
    }
    return input;
}

input_s case_setenv(input_s input)
{
    int count = 0;

    while (input.array[count] != NULL)
        count++;
    if (count == 1) {
        case_env(input);
        return input;
    }
    if ((input.array[1][0] < 65 || input.array[1][0] > 90
    && input.array[1][0] < 97 || input.array[1][0] > 122)
    && input.array[1][0] != '_') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        exit(1);
    }
    input = setenv_error_handling(input, count);
    return input;
}
