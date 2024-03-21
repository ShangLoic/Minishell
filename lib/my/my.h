/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Workshop
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <ucontext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>
#include <stdarg.h>
#pragma once

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
int my_printf(char const *format, ...);
int core(char const *format, int i, va_list list);
int wrong_first_flag(char const *format, int i, va_list list);
int my_putlong(long long nb);
int base_converter(long long number, int base, bool maj, int nb);
void base_display(int divised, bool maj);
void my_put_flt(double number, int nb);
int my_put_expoo(double f, int i, char e, int a);
int counti(int count);
void le_e(char e);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int disp_s(char *list, int nb);
int disp_i_d(long long list, int nb);
int flag_checker_complex(char const *format, int i, va_list list, int nb);
int flag_checker_complex2(char const *format, int i, va_list list, int nb);
int flag_checker_basics(char const *format, int i, va_list list, int nb);
