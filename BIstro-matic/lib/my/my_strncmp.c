/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** compare n first char
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int cond = 1;
    for (i; s1[i] != '\0' && s2[i] != '\0' && cond == 1 && i < n; i++) {
        if (s1[i] != s2[i]) cond = 0;
    }
    if (s1[i] != s2[i]) cond = 0;
    if (cond == 1) {
        return 0;
    } else {
        return s1[i] - s2[i];
    }
}
