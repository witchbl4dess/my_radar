/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
