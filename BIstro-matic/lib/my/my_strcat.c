/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** append two string
*/

char *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int i = 0;
    for (len; dest[len] != '\0'; len++);
    for (i; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
