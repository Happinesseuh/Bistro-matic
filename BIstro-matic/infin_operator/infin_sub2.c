/*
** EPITECH PROJECT, 2020
** infin_sub.c
** File description:
** infin_sub2
*/

static char *clean_str(char *str)
{
    int i = 0;
    int neg = 0;
    if (*str == '-') {
        neg = -1 + i++;
    }
    for (; str[i] == '0' && str[i + 1] != '\0'; i++);
    str[i-1] = '-';
    return str + i + neg;
}

static void my_swap_ptr(char **ptr1, char **ptr2)
{
    char *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

static void add_neg_sign(char *tmp, char const *str2, int len)
{
    int i = 1;
    tmp[0] = '-';
    for (; i <= len; i++)
        tmp[i] = str2[i - 1];
    tmp[i] = '\0';
}
