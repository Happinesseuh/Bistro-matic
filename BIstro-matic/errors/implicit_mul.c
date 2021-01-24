/*
** EPITECH PROJECT, 2020
** bracket2.c
** File description:
** implicit mul bracket
*/

#include "../include/bistromatic.h"
#include "../include/my_evalexpr.h"
#include <stdlib.h>
#include <unistd.h>

void err_implicit_mul(char *str)
{
    for (int i = 1; str[i] != '\0'; i++)
        if (str[i] == '(' && is_num(str[i - 1])) {
            write(2, SYNTAX_ERROR_MSG, 12);
            exit(84);
        }
}
