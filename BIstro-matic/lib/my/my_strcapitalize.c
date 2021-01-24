/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my_strcapitalize
*/

#include <stdio.h>

char *my_strcapitalize(char *str)
{
    int cond = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        cond = 0;
        if (!(str[i-1] >= 48 && str[i-1] <= 57))
            cond = 1;
        if (!(str[i-1] >= 65 && str[i-1] <= 90) && cond == 1)
            cond = 2;
        if (!(str[i-1] >= 97 && str[i-1] <= 122) && cond == 2)
            cond = 3;
        if (str[i] >= 97 && str[i] <= 122 && cond == 3)
            str[i] -= 32;
    }
    return str;
}
