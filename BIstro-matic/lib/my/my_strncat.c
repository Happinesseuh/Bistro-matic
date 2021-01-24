/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** append n first char of as sting to a string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = 0;
    int i = 0;
    for (len; dest[len] != '\0'; len++);
    for (i; src[i] != '\0' && i < nb; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
