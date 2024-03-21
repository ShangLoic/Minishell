/*
** EPITECH PROJECT, 2024
** aezfzrg
** File description:
** efzger
*/

#include "my.h"

int unsetenv_search(input_s input)
{
    int i = input.ev_len;

    input.unset = false;
    for (; input.ev[i] != NULL; i++) {
        if (my_strcmp(input.array[1], input.ev[i]) == 0) {
            input.unset = true;
            break;
        }
    }
    if (input.unset == true)
        return i;
    else
        return -1;
}

input_s unsetenv_error_handling(input_s input, int count)
{
    int j;

    if (count < 2) {
        my_printf("unsetenv: Too few arguments\n");
        exit(1);
    }
    for (int i = 1; input.array[i] != NULL; i++) {
        j = search_line_in_array(input.ev, my_strcat(input.array[i], "="));
        for (; input.ev[j + 1] != NULL && j >= 0; j++)
            my_swap(&input.ev[j], &input.ev[j + 1]);
        input.ev[j] = NULL;
    }
    return input;
}

input_s case_unsetenv(input_s input)
{
    int count = 0;

    input.array = str_to_array(input.line);
    if (my_strcmp(input.array[0], "unsetenv") == 0) {
        while (input.array[count] != NULL)
            count++;
        unsetenv_error_handling(input, count);
    }
    return input;
}

void case_env(input_s input)
{
    for (int i = 0; input.ev[i] != NULL; i++)
        my_printf("%s\n", input.ev[i]);
}
