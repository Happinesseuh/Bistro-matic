/*
** EPITECH PROJECT, 2020
** cond_function2.c
** File description:
** conditions for the function
*/

int is_operator(char c);

int is_strong_op(char c);

int is_weak_op(char c);

int is_num(char c);

int is_neg_sign(int i, char const *str);

int is_neg_bracket(int i, char *const str)
{
    if (str[i] == '-' && str[i + 1] == '(') {
        if (i == 0)
            return (1);
        else if (is_operator(str[i - 1]))
            return (1);
    }
    return (0);
}

int is_w_op_not_neg(int i, char *const str)
{
    if (is_weak_op(str[i]) && !is_neg_sign(i, str)
        && !is_neg_bracket(i, str))
        return 1;
    return 0;
}

int is_strong_op_or_plus_on_minus(char *const str, int i, char *stack, int k)
{
    if (str[i] == '+' && stack[k - 1] == '-')
        return 1;
    if (is_strong_op(stack[k-1]))
        return 1;
    return 0;
}

int is_str_op_or_bracket(int i, char *const str)
{
    if (is_strong_op(str[i]) || str[i] == '(')
        return 1;
    return 0;
}

