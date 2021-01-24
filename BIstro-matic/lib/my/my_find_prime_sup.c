/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** find prime sup
*/

static int my_is_prime2(int nb2)
{
    if (nb2 <= 0 || nb2 == 1) return 0;
    for (int i = 2; i < nb2; i++) if (nb2 % i == 0) return 0;
    return 1;
}

int my_find_prime_sup(int nb)
{
    if (nb <= 1) return 2;
    for (nb; my_is_prime2(nb) == 0; nb++) if (my_is_prime2(nb) == 1);
    return nb;
}
