/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** putstr
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; *str != '\0'; str = str + 1) my_putchar(*str);
    return 0;
}
