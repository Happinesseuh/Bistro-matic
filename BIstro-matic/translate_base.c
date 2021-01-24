/*
** EPITECH PROJECT, 2020
** translate_base
** File description:
** translate string in base given as parameter
*/

#include <stdlib.h>
#include "./include/my.h"
#include <stdio.h>
#include "./lib/my/my_evalexpr.h"

char *translate_base(char const *str, char const *base, char const *base_origin)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *result = malloc(sizeof(char) * my_strlen(str));
    int bool = 1;

    for (; str[i] != '\0'; i++) {
        bool = 1;
        for (j = 0; base[j] != '\0' && bool; j++) {
            if (str[i] == base[j]) {
                result[k] = base_origin[j];
                bool = 0;
            }
        }
        if (bool)
            result[k] = str[i];
        k += 1;
    }
    result[k] = '\0';
    return result;
}
