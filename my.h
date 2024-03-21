/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Workshop
*/

#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <ucontext.h>
#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

typedef struct input_t {
    char **array;
    int status;
    pid_t child;
    char *line;
    char **ev;
    int ev_len;
    ssize_t len;
    char *prompt;
    bool action;
    bool acces;
    bool unset;
}input_s;

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(char **a, char **b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int n);
char *my_strdup(const char *a);
int my_printf(char const *format, ...);

//useful

int getstr(char *str, int space);
int count_line(char *a);
char **str_to_array(char *str);
char *my_strclean(char *str);
int nbrget(char *str);

//useful2

int number_of_arg(char *str, char separator);
char *search_str_in_array(char **array, char *str);
int search_line_in_array(char **array, char *str);
char *my_get_selected_str(char **array, char *str, char separator, int nb);
int count_nb_of_cmd(char *str);

//useful3

int nbrget(char *str);

//cases

int case_cd(input_s input);
int case_execve(input_s input);
input_s case_setenv(input_s input);
input_s case_unsetenv(input_s input);

//case_execve

input_s access_verif(input_s input);
input_s execve_other(input_s input);
int case_execve(input_s input);

//cases_setenv

input_s setenv_add(input_s input);
input_s setenv_replace(input_s input);
input_s setenv_error_handling(input_s input, int count);
input_s case_setenv(input_s input);

//case_unsetenv

int unsetenv_search(input_s input);
input_s unsetenv_error_handling(input_s input, int count);
input_s case_unsetenv(input_s input);
void case_env(input_s input);

//case_cd

input_s cd_others(input_s input, char *buff);
int case_cd(input_s input);

//others

void free_all(input_s input);

//mysh

int status_check(input_s input);
input_s filter_scdpart(input_s input);
int filter(input_s input);
input_s init_input(input_s input, char **ev);
//main
