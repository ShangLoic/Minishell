/*
** EPITECH PROJECT, 2024
** printf
** File description:
** bttf
*/

#include "my.h"

int flag_checker_basics(char const *format, int i, va_list list, int nb)
{
    switch (format[i]) {
    case 'd':
    case 'i':
        return disp_i_d(va_arg(list, int), nb);
    case 'c':
        my_putchar((char)va_arg(list, int));
        return 0;
    case 'f':
        my_put_flt(va_arg(list, double), nb);
        return 0;
    case 's':
        return disp_s(va_arg(list, char *), nb);
    default:
        return flag_checker_complex(format, i, list, nb);
    }
}

int flag_checker_complex2(char const *format, int i, va_list list, int nb)
{
    switch (format[i]) {
    case 'E':
        my_put_expoo(va_arg(list, double), 10, 'E', 6);
        return 0;
    case 'u':
        base_converter(va_arg(list, int), 10, 0, nb);
        return 0;
    case 'o':
        base_converter(va_arg(list, int), 8, 1, nb);
        return 0;
    case '%':
        my_putchar('%');
        return 0;
    }
    return 84;
}

int flag_checker_complex(char const *format, int i, va_list list, int nb)
{
    switch (format[i]) {
    case 'x':
        base_converter(va_arg(list, int), 16, 0, nb);
        return 0;
    case 'X':
        base_converter(va_arg(list, int), 16, 1, nb);
        return 0;
    case 'p':
        my_putstr("0x");
        base_converter(va_arg(list, long), 16, 0, nb);
        return 0;
    case 'e':
        my_put_expoo(va_arg(list, double), 10, 'e', 6);
        return 0;
    default:
        return flag_checker_complex2(format, i, list, nb);
    }
}

int disp_i_d(long long list, int nb)
{
    int copy = list;

    if (nb != -1) {
        while (copy > 0) {
            copy /= 10;
            nb--;
        }
        while (nb > 0) {
            nb--;
            my_putchar('0');
        }
    }
    my_putlong(list);
    return 0;
}

int disp_s(char *list, int nb)
{
    if (nb > -1) {
        for (int i = 0; i < nb && list[i] != '\0'; i++) {
            my_putchar(list[i]);
        }
    } else
        my_putstr(list);
    return 0;
}
