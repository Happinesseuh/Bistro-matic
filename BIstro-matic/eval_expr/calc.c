/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** eval_expr
*/

#include "../include/my.h"
#include "../include/my_evalexpr.h"
#include <stdlib.h>

static int my_strlen_arr(char **arr)
{
    int i = 0;
    for (; arr[i][0] != '\0'; i++);
    return i;
}

char *calc(char **arr)
{
    char **stack = malloc(sizeof(char *) * my_strlen_arr(arr));
    int i = 0;
    int j = 0;
    for (; arr[i][0] != '\0'; i += 1) {
        if (is_operator(arr[i][0]) && arr[i][1] == '\0') {
            stack[j - 2] = do_op(stack[j - 2], stack[j - 1], arr[i][0]);
            j -= 1;
        } else {
            stack[j] = arr[i];
            j += 1;
        }
    }
    return stack[0];
}
