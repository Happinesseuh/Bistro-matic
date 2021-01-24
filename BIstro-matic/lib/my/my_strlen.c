/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** str len
*/

int my_strlen(char const *str)
{
    int c = 0;
    for (c; str[c] != '\0'; c++);
    return c;
}
