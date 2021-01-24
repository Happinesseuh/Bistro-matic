/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** show word array
*/

#include <stdlib.h>

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int maxlen = 0;
    int a = 0;
    char *str;
    for (int i = 0; tab[i] != 0 && tab[i] != "\0"; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) maxlen++;
        maxlen++;
    }
    str = malloc(sizeof(char) * (maxlen + 1));
    for (int i = 0; tab[i] != 0 && tab[i] != "\0"; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            str[a] = tab[i][j];
            a++;
        }
        if (a != maxlen - 1) str[a] = '\n';
        a++;
    }
    my_putstr(str);
    free(str);
}
