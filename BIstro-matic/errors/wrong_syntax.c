/*
** EPITECH PROJECT, 2020
** wrong_syntax.c
** File description:
** wrong_syntax
*/

#include "../include/bistromatic.h"
#include "../include/my_evalexpr.h"
#include <stdlib.h>
#include <unistd.h>

void err_wrong_syntax(char **str)
{
    int nb = 0;
    int op = 0;

    for (int i = 0; str[i][0] != '\0'; i++) {
        if (is_operator(str[i][0]) && str[i][1] == '\0')
            op += 1;
        else
            nb += 1;
    }
    if (!(nb - 1 == op)) {
        write(2, SYNTAX_ERROR_MSG, 12);
        exit(84);
    }
}
