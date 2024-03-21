/*
** EPITECH PROJECT, 2024
** aezfzrg
** File description:
** efzger
*/

#include "my.h"

input_s cd_others(input_s input, char *buff)
{
    if (input.line[3] == '-' && input.line[4] == '\0') {
        if (my_strcmp(search_str_in_array(input.ev, "OLDPWD="),
        search_str_in_array(input.ev, "PWD=")) == 0) {
            my_printf(": no such file or directory.\n");
            exit(1);
        } else
            chdir(search_str_in_array(input.ev, "OLDPWD="));
    } else if (chdir(input.array[1]) == 0) {
        input.line = my_strcat("setenv OLDPWD ", buff);
        input.array = str_to_array(input.line);
        case_setenv(input);
        buff = getcwd(NULL, 0);
        input.line = my_strcat("setenv PWD ", buff);
        input.array = str_to_array(input.line);
        case_setenv(input);
    } else {
        my_printf("%s: Not a directory.\n", input.array[1]);
        exit(1);
    }
        return input;
}

int case_cd(input_s input)
{
    ssize_t size;
    char *buff = getcwd(NULL, 0);

    if (input.line[2] == '\0' || input.line[2] == ' ' &&
    input.line[3] == '~' && input.line[4] == '\0' ||
    input.line[2] == ' ' && input.line[3] == '-' &&
    input.line[4] == '-' && input.line[5] == '\0') {
        input.line = my_strcat("setenv OLDPWD ", buff);
        input.array = str_to_array(input.line);
        case_setenv(input);
        chdir(search_str_in_array(input.ev, "HOME="));
        buff = getcwd(NULL, 0);
        input.line = my_strcat("setenv PWD ", buff);
        input.array = str_to_array(input.line);
        case_setenv(input);
    } else if (input.line[2] == ' ') {
        input = cd_others(input, buff);
    }
}
