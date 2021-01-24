/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** compare string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int cond = 1;
    for (i; s1[i] != '\0' && s2[i] != '\0' && cond == 1; i++) {
        if (s1[i] != s2[i]) cond = 0;
    }
    if (s1[i] != s2[i]) cond = 0;
    if (cond == 1) {
        return 2;
    } else if (s1[i] - s2[i] < 0) {
        return -1;
    } else {
        return 1;
    }
}
