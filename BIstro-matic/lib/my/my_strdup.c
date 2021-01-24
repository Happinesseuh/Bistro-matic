/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** deuplicate string
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src)));
    for (int i = 0; i < my_strlen(src); i++) str[i] = src[i];
    return str;
}
