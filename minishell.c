/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** daefvz
*/

#include "my.h"

int status_check(input_s input)
{
    if (!WIFEXITED(input.status)) {
        if (__WCOREDUMP(input.status)) {
            my_printf("Segmentation fault (core dumped)\n");
            exit(139);
        }
        my_printf("Segmentation fault\n");
        exit(139);
    }
    if (input.status == 256)
        exit(1);
}

input_s filter_scdpart(input_s input)
{
    if (my_strcmp(input.array[0], "unsetenv") == 0 && input.action == false) {
        input = case_unsetenv(input);
        input.action = true;
    }
    if (my_strcmp(input.line, "env") == 0 && input.action == false) {
        case_env(input);
        input.action = true;
    }
    if (my_strcmp(input.array[0], "cd") == 0 && input.action == false) {
        case_cd(input);
        input.action = true;
    }
    if (input.array[0] != NULL && input.action == false) {
        case_execve(input);
    }
    return input;
}

int filter(input_s input)
{
    if (my_strcmp(input.array[0], "exit") == 0 && input.action == false) {
        if (input.array[1] != NULL)
            exit(nbrget(input.array[1]));
        else
            exit(0);
        input.action = true;
    }
    if (my_strcmp(input.array[0], "setenv") == 0 && input.action == false) {
        input = case_setenv(input);
        input.action = true;
    }
    input = filter_scdpart(input);
}

input_s init_input(input_s input, char **ev)
{
    input.len = 0;
    input.line = NULL;
    input.ev = ev;
    input.prompt = "$> ";
    return input;
}

int main(int ac, char **av, char **ev)
{
    input_s input = init_input(input, ev);

    for (input.ev_len = 0; input.ev[input.ev_len] != NULL; input.ev_len++)
    if (ac != 1)
        return 84;
    while (1) {
        if (isatty(0) == 1)
            my_printf(input.prompt);
        for (int i = 0; getline(&input.line, &input.len, stdin) != -1; i++) {
            input.line = my_strclean(input.line);
            input.action = false;
            input.child = 1;
            input.array = str_to_array(input.line);
            filter(input);
        }
        if (isatty(0) != 1)
            exit(0);
    }
    free_all(input);
    return 0;
}
