/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** displays each string in the array, one per line
*/
#include "my.h"
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar(10);
    }
    return (0);
}
