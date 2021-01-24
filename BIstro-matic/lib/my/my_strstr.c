/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** search a string
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    for (i; str[i] != '\0'; i++) {
        int cond = 1;
        int j = 0;
        for (j; str[i] != '\0' && to_find[j] != '\0' && cond == 1; j++) {
            if (str[i + j] != to_find[j]) cond = 0;
        }
        if (cond == 1) return &str[i];
    }
    return '\0';
}
