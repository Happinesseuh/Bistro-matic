/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** power
*/

int my_compute_power_rec(int nb, int p)
{
    int total = 1;
    if (p == 0) return 1;
    if (p < 0) return 0;
    total = nb * my_compute_power_rec(nb, p - 1);
    return total;
}
