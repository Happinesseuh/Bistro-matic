/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** get nbr
*/

static int is_digit(char c)
{
    if (c >= 48 && c <= 57) return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int res = 0;
    int neg = 1;
    int i = 0;
    for (; str[i] == '+' || str[i] == '-'; i += 1)
        if (str[i] == '-')
            neg = -neg;
    if (!is_digit(str[i]))
        return 0;
    for (i; is_digit(str[i]); i++) {
        if (res > 214748364) return 0;
        if (res == 214748364) {
            if (neg == 1 && str[i] > '7')
                return 0;
            if (neg == -1 && str[i] > '8')
                return 0;
            return neg * res * 10 + neg * (str[i] - '0');
        }
        res = res * 10 + (str[i] - '0');
    }
    return neg * res;
}
