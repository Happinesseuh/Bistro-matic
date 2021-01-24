/*
** EPITECH PROJECT, 2020
** infin_sub.c
** File description:
** infin_sub
*/

#include <stdlib.h>
#include <stddef.h>
#include "../include/my.h"
#include "infin_sub2.c"

#define COMPARE(x, y) (((x) > (y)) ? (x):(y))

#define CTOI(x) ((x) - '0')

#define ITOC(x) ((x) + '0')

char *infin_add(char const *, char const *);

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

static void my_sub(int a, char *result, int i, int *rest)
{
    result[i] = a - *rest;
    if (result[i] < 0) {
        *rest = 1;
        result[i] = result[i] + 10;
    } else {
        *rest = 0;
    }
    result[i] = ITOC(result[i]);
}

static void final_rest(char *result, int *i, int rest)
{
    if (rest > 0) {
        result[*i] = ITOC(rest);
        *i += 1;
    }
}

static void split_inf_sub(char const *str1, char const *str2,
                          char *result, int *rest)
{
    int i = 0;
    char *rstr1 = my_revstr(my_strdup(str1));
    char *rstr2 = my_revstr(my_strdup(str2));
    int neg = 1;
    if (is_lower(str1, str2)) {
        neg = -1;
        my_swap_ptr(&rstr1, &rstr2);
    }
    for (i = 0; rstr1[i] != '\0' && rstr2[i] != '\0'; i += 1)
        my_sub(CTOI(rstr1[i]) - CTOI(rstr2[i]), result, i, rest);
    if (rstr1[i] != '\0') {
        for (; rstr1[i] != '\0'; i++) {
            my_sub(CTOI(rstr1[i]), result, i, rest);
        }
    } else if (rstr2[i] != '\0') {
        for (; rstr2[i] != '\0'; i++)
            my_sub(CTOI(rstr2[i]), result, i, rest);
    }
    final_rest(result, &i, *rest);
    if ((str1[-1]  == '-' && str2[-1] == '-') ^ (neg == -1))
        result[i++] = '-';
        result[i] = '\0';
}

char *infin_sub(char const *str1, char const *str2)
{
    int len = COMPARE(my_strlen(str1), my_strlen(str2));
    char *result = malloc(len + 1);
    int rest = 0;
    char *tmp = malloc(len + 2);
    int i = 1;
    if (*str1 == '-' && *str2 != '-') {
        add_neg_sign(tmp, str2, len);
        return infin_add(str1, tmp);
    } else if (*str1 != '-' && *str2 == '-') {
        return infin_add(str1, str2 + 1);
    }
    if (*str1 == '-')
        str1 = str1 + 1;
    if (*str2 == '-')
        str2 = str2 + 1;
    if (result == NULL)
        return NULL;
    for (int j = 0; j < len + 2; j++)
        result[j] = '0';
    split_inf_sub(str1, str2, result, &rest);
    result = clean_str(my_revstr(result));
    return result;
}
