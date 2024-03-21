/*
** EPITECH PROJECT, 2024
** defsgzer
** File description:
** gerht
*/

#include "my.h"

void free_all(input_s input)
{
    free(input.array);
    free(input.ev);
    free(input.line);
    free(input.prompt);
}
