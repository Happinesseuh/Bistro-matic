/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n character from source
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = 0;
    for (len; dest[len] != '\0'; len++);
    for (i; src[i] != '\0' && dest[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    if (n > len) dest[i] = '\0';
    return dest;
}
