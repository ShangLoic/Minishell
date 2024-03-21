/*
** EPITECH PROJECT, 2024
** eafz
** File description:
** fezgr
*/

#include "my.h"


input_s access_verif(input_s input)
{
    char *copy = input.array[0];

    input.acces = false;
    for (int i = 0; i < number_of_arg(input.ev
    [search_line_in_array(input.ev, "PATH=")], ':') + 1; i++) {
        input.array[0] = my_strcat(my_strcat
        (my_get_selected_str(input.ev, "PATH=", ':', i), "/"), copy);
        if (access(input.array[0], X_OK) == 0) {
            input.acces = true;
            break;
        }
    }
    if (input.acces != true) {
        input.array = str_to_array(input.line);
        my_printf("%s: Command not found.\n", input.array[0]);
        input.acces = true;
        exit(1);
    }
    return input;
}

input_s execve_other(input_s input)
{
    if (opendir(input.array[0]) != NULL) {
        my_printf("%s: Permission denied.\n", input.array[0]);
        exit(1);
    } else if (open(input.array[0], O_RDONLY) != -1) {
        return input;
    } else {
        input = access_verif(input);
    }
    return input;
}

int case_execve(input_s input)
{
    if (input.child != 0) {
        input.child = fork();
    }
    if (input.child == 0) {
        input = execve_other(input);
        if (execve(input.array[0], input.array, input.ev) == -1
        && input.action == true) {
            exit(1);
        }
        if (input.acces != true) {
            my_printf("%s: Exec format error. Wrong Architecture.\n",
            input.array[0]);
            exit(1);
        }
    }
    waitpid(input.child, &input.status, WUNTRACED);
    status_check(input);
}
