/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reveerse a string
*/

char *my_revstr(char *str)
{
    int len = 0;
    for (len; str[len] != '\0'; len++);
    len--;
    for (int i = 0; i <= len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    return str;
}
