/*
** EPITECH PROJECT, 2020
** conversion
** File description:
** convert infix notations into the two ones
*/

#include "../include/my.h"
#include "../include/my_evalexpr.h"
#include "conversion2.c"
#include <stdlib.h>

static void number_conversion(char const *str, int *i, int *j, char **arr)
{
    int size = 0;
    int k = 0;

    if (str[*i + size] == '-')
        size += 1;
    for (; str[*i + size] >= '0' && str[*i + size] <= '9'; size += 1);
    arr[*j] = malloc(sizeof(char) * size);
    if (str[*i] == '-') {
        arr[*j][k] = str[*i];
        k += 1;
        *i += 1;
    }
    for (; str[*i] >= '0' && str[*i] <= '9'; *i += 1) {
        arr[*j][k] = str[*i];
        k += 1;
    }
    *j += 1;
    *i -= 1;
}

static char **final_conversion(char *stack, char **arr, int *k, int *j)
{
    push_stack(stack, arr, k, j);
    free(stack);
    arr[*j] = malloc(1);
    arr[*j][0] = '\0';
    return arr;
}

static void neg_bracket(char *stack, char **arr, int *k, int *j)
{
    stack[*k] = '*';
    *k += 1;
    arr[*j] = malloc(sizeof(char) * 2);
    arr[*j][0] = '-';
    arr[*j][1] = '1';
    *j += 1;
}

char **conversion(char const *str)
{
    char *stack = malloc(sizeof(char) * my_strlen(str));
    char **arr = malloc(sizeof(char *) * my_strlen(str));
    int j = 0;
    int k = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_w_op_not_neg(i, str) && k != 0) {
            if (is_strong_op_or_plus_on_minus(str, i, stack, k))
                push_stack(stack, arr, &k, &j);
            top_stack(stack, str, &k, i);
        }
        if (is_str_op_or_bracket(i, str) || (is_w_op_not_neg(i, str) && k == 0))
            top_stack(stack, str, &k, i);
        if (str[i] == ')')
            push_stack(stack, arr, &k, &j);
        if (is_num(str[i]) || is_neg_sign(i, str))
            number_conversion(str, &i, &j, arr);
        if (is_neg_bracket(i, str))
            neg_bracket(stack, arr, &k, &j);
    }
    return final_conversion(stack, arr, &k, &j);
}
