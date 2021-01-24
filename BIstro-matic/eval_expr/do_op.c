/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/my_evalexpr.h"

char *infin_add(char const *a, char const *b);

char *infin_sub(char const *a, char const *b);

char *infin_mul(char const *a, char const *b);

char *infin_div(char const *a, char const *b);

char *infin_mod(char const *a, char const *b);

char *do_op(char *a, char *b, char op)
{
    char *(*operator[48])(char const *, char const *);

    operator['+'] = &infin_add;
    operator['-'] = &infin_sub;
    operator['*'] = &infin_mul;
    operator['/'] = &infin_div;
    operator['%'] = &infin_mod;
    return operator[op](a, b);
}
