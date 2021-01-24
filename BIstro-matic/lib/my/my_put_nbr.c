/*
** EPITECH PROJECT, 2020
** my_put_number.c
** File description:
** put nbr
*/

int my_putchar(char c);

static int power(int to_power, int power)
{
    int total;

    total = 1;
    for (int i = 0; i < power; i++) {
        total = total * to_power;
    }
    return total;
}

static int count_decimal(int nb)
{
    int count = 0;
    for (count; nb != 0; nb /= 10) count++;
    return count;
}

static int my_put_nbr_exception(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int count;
    int number;
    int to_print;

    if (nb == -2147483648) {
        my_put_nbr_exception();
    } else {
        if (nb == 0) my_putchar(48);
        if (nb < 0) {
            my_putchar('-');
            nb = -(nb);
        }
        count = count_decimal(nb);
        for (count; count > 0; count--) {
            to_print = nb / power(10, count - 1);
            my_putchar(to_print + 48);
            nb = nb - (to_print * power(10, count - 1));
        }
    }
    return 0;
}
