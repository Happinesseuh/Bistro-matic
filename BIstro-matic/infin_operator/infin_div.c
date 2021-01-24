/*
** EPITECH PROJECT, 2020
** infin_div.c
** File description:
** Functions to divide two large numbers
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

static char *clean_str(char *str)
{
    int i = 0;
    for (; str[i] == '0' && str[i + 1] != '\0'; i++);
    return str + i;
}

static char *div_calc(char *result, char *divide, char *quotient, int max_size)
{
    while (max_size >= 0) {
        if (is_lower(result, divide)) {
            divide[my_strlen(divide) - 1] = '\0';
            max_size -= 1;
        } else {
            result = infin_sub(result, divide);
            quotient[max_size] += 1;
        }
    }
    my_revstr(quotient);
    quotient = clean_str(quotient);
    quotient[-1] = '-';
    return quotient;
}

static void start(char const *str1, char **str2cpy, char **result, int *neg)
{
    if (str2cpy[0][0] == '0' && str2cpy[0][1] == '\0') {
        write(2, ERROR_MSG, 5);
        exit(84);
    }
    if (*str1 == '-' ^ **str2cpy == '-')
        *neg = -1;
    if (*str1 == '-')
        *result = *result + 1;
    if (**str2cpy == '-')
        *str2cpy = *str2cpy + 1;
}

char *infin_div(char const *str1, char const *str2)
{
    char *divide = malloc(my_strlen(str1) + 1);
    char *result = my_strdup(str1);
    char *str2cpy = my_strdup(str2);
    int max_size = 0;
    char *quotient;
    int neg = 1;
    start(str1, &str2cpy, &result, &neg);
    if (is_lower(str1, str2cpy))
        return "0";
    for (int i = 0; i < my_strlen(str2cpy); i++)
        divide[i] = str2cpy[i];
    for (int i = my_strlen(divide); i < my_strlen(result); divide[i++] = '0')
        max_size += 1;
    quotient = malloc(max_size + 2);
    quotient = quotient + 1;
    for (int i = 0; i <= max_size; i++)
        quotient[i] = '0';
    if (neg == -1)
        return div_calc(result, divide, quotient, max_size) - 1;
    return div_calc(result, divide, quotient, max_size);
}
