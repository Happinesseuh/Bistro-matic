/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** sort array of int
*/

static int my_swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}

static int my_int_cmp(int *a, int *b)
{
    if (*a > *b) return my_swap_int(a, b);
    return 0;
}

void my_sort_int_array(int *array, int size)
{
    int cond = 1;
    while (cond >= 1) {
        cond = 0;
        for (int i = 1; i < size; i++) {
            cond += my_int_cmp(&array[i-1], &array[i]);
        }
    }
}
