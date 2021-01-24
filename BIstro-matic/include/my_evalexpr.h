/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** header
*/

#ifndef MY_EVALEXPR_
#define MY_EVALEXPR_

char *do_op(char *a, char *b, char op);
char *calc(char **arr);
int is_operator(char c);
int is_strong_op(char c);
int is_weak_op(char c);
int is_num(char c);
int is_neg_sign(int i, char const *str);
int is_neg_bracket(int i, char const *str);
int is_w_op_not_neg(int i, char const *str);
int is_strong_op_or_plus_on_minus(char const *str, int i, char *stack, int k);
int is_str_op_or_bracket(int i, char const *str);
char **conversion(char const *str);

#endif /* MY_EVALEXPR_ */
