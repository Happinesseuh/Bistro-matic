/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c for project EvalExpr
*/

#include "../include/my_evalexpr.h"
#include "../include/my.h"
#include "../include/my_err.h"

char *translate_base(char *, char const *, char const *);

char *eval_expr(char const *numbase, char const *opbase,
                char *str, unsigned int size)
{
    char **pni;
    char *result;

    str = translate_base(str, numbase, "0123456789");
    str = translate_base(str, opbase, "()+-*/%");
    err_brackets(str);
    err_implicit_mul(str);
    pni = conversion(str);
    err_wrong_syntax(pni);
    result = calc(pni);
    result = translate_base(result, "0123456789", numbase);
    return result;
}
