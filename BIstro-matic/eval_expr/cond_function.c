/*
** EPITECH PROJECT, 2020
** cond function
** File description:
** cond function
*/

int is_operator(char c)
{
    if (c == '+')
        return 1;
    if (c == '-')
        return 1;
    if (c == '*')
        return 1;
    if (c == '/')
        return 1;
    if (c == '%')
        return 1;
    return 0;
}

int is_strong_op(char c)
{
    if (c == '*')
        return 1;
    if (c == '/')
        return 1;
    if (c == '%')
        return 1;
    return 0;
}

int is_weak_op(char c)
{
    if (c == '+')
        return 1;
    if (c == '-')
        return 1;
    return 0;
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int is_neg_sign(int i, char const *str)
{
    if (str[i] == '-') {
        if (str[i + 1] == '(')
            return 0;
        if (i == 0) {
            return (1);
        }else {
            if (!is_num(str[i - 1]) && str[i - 1] != ')')
                return (1);
        }
    }
    return (0);
}
