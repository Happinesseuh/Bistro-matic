/*
** EPITECH PROJECT, 2020
** bracket.c
** File description:
** fix errors due to brackets
*/

#include "../include/bistromatic.h"
#include <stdlib.h>
#include <unistd.h>

void err_brackets(char *str)
{
    int bracket1 = 0;
    int bracket2 = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '(')
            bracket1 += 1;
        if (str[i] == ')')
            bracket2 += 1;
    }
    if (bracket1 != bracket2) {
        write(2, SYNTAX_ERROR_MSG, 12);
        exit(84);
    }
}
