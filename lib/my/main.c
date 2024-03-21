/*
** EPITECH PROJECT, 2024
** printf
** File description:
** bttf
*/

#include "my.h"

int wrong_first_flag(char const *format, int i, va_list list)
{
    int nb = 0;

    if (format[i] == '.') {
        i++;
        for (; format[i] >= 48 && format[i] <= 57; i++)
            nb = (nb * 10) + (format[i] - 48);
        flag_checker_basics(format, i, list, nb);
    } else if (flag_checker_basics(format, i, list, -1) != 0)
        my_putchar('%');
    return i;
}

int core(char const *format, int i, va_list list)
{
    if (format[i] == '%') {
        i++;
        i = wrong_first_flag(format, i, list);
    } else
        my_putchar(format[i]);
    return i;
}

int my_printf(char const *format, ...)
{
    va_list list;
    int j = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++)
        i = core(format, i, list);
    va_end(list);
    return 0;
}
