/*
** EPITECH PROJECT, 2020
** conversion2.c
** File description:
** conversion file (2)
*/

#include <stdlib.h>

static void push_stack(char *stack, char **arr, int *k, int *j)
{
    *k -= 1;
    for (; *k >= 0 && stack[*k] != '('; *k -= 1) {
        arr[*j] = malloc(1);
        arr[*j][0] = stack[*k];
        *j += 1;
    }
    if (stack[*k] != '(')
        *k += 1;
}

static void top_stack(char *stack, char const * str, int *k, int i)
{
    stack[*k] = str[i];
    *k += 1;
}
