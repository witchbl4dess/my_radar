/*
** EPITECH PROJECT, 2023
** my_sort_int_array.c
** File description:
** sorts an integer array in ascending order
*/

static void i_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void my_sort_int_array(int *array, int size)
{
    int k = 0;
    int mem;

    for (; k < size; k++) {
        mem = k;
        for (int i = k; i < size; i++) {
            mem = array[i] <= array[mem] ? i : mem;
        }
        i_swap(array + k, array + mem);
    }
}
