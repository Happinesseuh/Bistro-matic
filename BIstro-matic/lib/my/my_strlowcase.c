/*
** EPITECH PROJECT, 2020
** my_strlowcase.c
** File description:
** my_strlowcase.c
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
    }
    return str;
}
