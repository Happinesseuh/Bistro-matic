/*
** EPITECH PROJECT, 2020
** multinf.c
** File description:
** Multiply numbers in two strings
*/

#include "../include/my.h"
#include <stdlib.h>

#define ITOC(i) (i + '0')

#define CTOI(i) (i - '0')

char *product_of_strings(char *a, char *b, char *out)
{
    int i;
    int j;
    for (i = my_strlen(a) - 1; i >= 0; i-- ) {
        for (j = my_strlen(b) - 1; j >= 0; j-- ) {
            out[i + j + 1] += (CTOI(b[j])) * (CTOI(a[i]));
            if (out[i + j + 1] >= 10) {
                out[i + j] += out[i + j + 1] / 10;
                out[i + j + 1] %= 10;
            }
        }
    }
    for (i = my_strlen(a) + my_strlen(b); i >= 0; i--) {
        out[i] = ITOC(out[i]);
    }
    out[my_strlen(a) + my_strlen(b)] = '\0';
    return (out);
}

void cant_touch_this(char **out, int bool_neg)
{
    if (bool_neg == 1 && *out[0] != '0')
        *out -= 1;
    if (bool_neg == 1 && *out[0] == '0')
        *out[0] = '-';
    if (*out[0] == '0')
        *out += 1;
}

char *infin_mul(char const *n1, char const *n2)
{
    char *a = my_strdup(n1);
    char *b = my_strdup(n2);
    char *out = malloc(my_strlen(a) + my_strlen(b) + 1);
    int bool_neg = 0;
    out++[0] = '-';
    if ((a[0] == '-') ^ (b[0] == '-'))
        bool_neg = 1;
    if (a[0] == '-')
        a++;
    if (b[0] == '-')
        b++;
    if ((a[0] == '0' ) || (b[0] == '0'))
        return ("0");
    out = product_of_strings(a, b, out);
    cant_touch_this(&out, bool_neg);
    return (out);
}
