/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** tell if prime or not
*/

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1) return 0;
    for (int i = 2; i < nb; i++) if (nb % i == 0) return 0;
    return 1;
}
