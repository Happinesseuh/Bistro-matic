/*
** EPITECH PROJECT, 2020
** infin_mod.c
** File description:
** infin_mod
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include <stdlib.h>
#include <unistd.h>

#define COMPARE(x, y) (((x) > (y)) ? (x):(y))

char *infin_sub(char const *, char const *);

static int is_lower(char const *str1, char const *str2)
{
    if (my_strlen(str1) < my_strlen(str2))
        return 1;
    if (my_strlen(str1) == my_strlen(str2)) {
        for (int i = 0; str1[i] != '\0'; i += 1) {
            if (str1[i] > str2[i])
                return 0;
            if (str1[i] < str2[i])
                return 1;
        }
        return 0;
    }
    return 0;
}

static char *mod_calc(char *result, char *divide, int max_size, int neg)
{
    while (max_size >= 0) {
        if (is_lower(result, divide)) {
            divide[my_strlen(divide) - 1] = '\0';
            max_size -= 1;
        } else {
            result = infin_sub(result, divide);
        }
    }
    result[-1] = '-';
    if (result[0] == '0')
        return result;
    if (neg == -1)
        return result - 1;
    return result;
}

void error_and_start(char const *str1, char **str2cpy, char **result, int *neg)
{
    if (str2cpy[0][0] == '0' && str2cpy[0][1] == '\0') {
        write(2, ERROR_MSG, 5);
        exit(84);
    }
    if (*str1 == '-') {
        *neg = -1;
        *result = *result + 1;
    }
    if (**str2cpy == '-')
        *str2cpy = *str2cpy + 1;
}

char *infin_mod(char const *str1, char const *str2)
{
    int len = my_strlen(str1);
    char *divide = malloc(len + 1);
    char *result = my_strdup(str1);
    char *str2cpy = my_strdup(str2);
    int max_size = 0;
    int neg = 1;

    error_and_start(str1, &str2cpy, &result, &neg);
    if (is_lower(str1, str2cpy))
        return result;
    for (int i = 0; i < my_strlen(str2cpy); i++)
        divide[i] = str2cpy[i];
    for (int i = my_strlen(divide); i < my_strlen(str1); i++) {
        divide[i] = '0';
        max_size += 1;
    }
    return mod_calc(result, divide, max_size, neg);
}
