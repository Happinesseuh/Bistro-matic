/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** show str
*/

#include <unistd.h>

void my_putchar(char);

#define DTOH(x) (((x) > 9) ? (x + 87):(x))

int my_showstr(char const *str)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 32 || str[i] > 127) {
            write(1, "\\", 1);
            (str[i] < 16) ? (my_putchar('0')):(0);
            for (n = str[i]; n/16 * 16 != 0; n = n - (n / 16 * 16)) {
                my_putchar(DTOH(n / 16));
            }
            my_putchar(DTOH(n));
        } else {
            write(1, &str[i], 1);
        }
    }
    return 0;
}
