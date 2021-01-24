/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stdio.h>

static int is_alpha(char c)
{
    if (c >= 48 && c <= 57) return 1;
    if (c >= 65 && c <= 90) return 1;
    if (c >= 97 && c <= 122) return 1;
    return 0;
}

static int count_nbword(char const *str)
{
    int nbword = 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_alpha(str[i]) == 0) nbword++;
    return nbword;
}

char **my_str_to_word_array(char const *str)
{
    int nbword = count_nbword(str);
    char **word_array;
    int cur_char = 0;
    int cur_char2 = 0;
    int size = 0;
    word_array = malloc(sizeof(char *) * (nbword + 2));
    for (int i = 0; i < nbword; i++) {
        for (size = 0; is_alpha(str[cur_char2]) == 1; size += 1)
            cur_char2 += 1;
        cur_char2 += 1;
        word_array[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; is_alpha(str[cur_char]) == 1; j += 1) {
            word_array[i][j] = str[cur_char];
            cur_char += 1;
        }
        cur_char += 1;
    }
    word_array[nbword] = malloc(1);
    word_array[nbword][0] = '\0';
    return word_array;
}
