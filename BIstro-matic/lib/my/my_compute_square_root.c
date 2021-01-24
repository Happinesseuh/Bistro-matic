/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** square roots
*/

int my_compute_square_root(int nb)
{
    if (nb < 0) return 0;
    for (int i = 0; i <= nb; i++) if ( i * i == nb) return i;
    return 0;
}
