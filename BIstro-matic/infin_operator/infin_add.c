/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** infin_add
*/

#include <stdlib.h>
#include <stddef.h>
#include "../include/my.h"

#define COMPARE(x, y) (((x) > (y)) ? (x):(y))

#define CTOI(x) ((x) - '0')

#define ITOC(x) ((x) + '0')

char *infin_sub(char const *, char const *);

static void my_add(int a, char *result, int i, int *rest)
{
    result[i] = *rest + a;
    if (result[i] > 9) {
        *rest = 1;
        result[i] = result[i] - 10;
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

static void split_inf_add(char const *str1, char const *str2,
                          char *result, int *rest)
{
    int i = 0;
    char *rstr1 = my_revstr(my_strdup(str1));
    char *rstr2 = my_revstr(my_strdup(str2));

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i += 1)
        my_add(CTOI(rstr1[i]) + CTOI(rstr2[i]), result, i, rest);
    if (str1[i] != '\0') {
        for (i; str1[i] != '\0'; i++) {
            my_add(CTOI(rstr1[i]), result, i, rest);
        }
    } else if (str2[i] != '\0') {
        for (i; str2[i] != '\0'; i++)
            my_add(CTOI(rstr2[i]), result, i, rest);
    }
    final_rest(result, &i, *rest);
    if (str1[-1]  == '-' && str2[-1] == '-')
        result[i++] = '-';
    result[i] = '\0';
}

char *infin_add(char const *str1, char const *str2)
{
    int len = COMPARE(my_strlen(str1), my_strlen(str2));
    char *result = malloc(len + 2);
    int rest = 0;
    char *tmp_str = malloc(len + 1);
    int i = 1;
    if (*str1 == '-' && *str2 != '-') {
        return infin_sub(str2, str1 + 1);
    } else if (*str1 != '-' && *str2 == '-') {
        return infin_sub(str1, str2 + 1);
    }
    if (*str1 == '-')
        str1 = str1 + 1;
    if (*str2 == '-')
        str2 = str2 + 1;
    if (result == NULL)
        return NULL;
    for (int j = 0; j < len + 2; j++)
        result[j] = '0';
    split_inf_add(str1, str2, result, &rest);
    result = my_revstr(result);
    return result;
}
