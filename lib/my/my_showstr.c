/*
** EPITECH PROJECT, 2023
** my_showstr.c
** File description:
** show the str
*/
#include "my.h"

int my_showstr(char const *str)
{
    char *base = "0123456789abcdef";

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putstr(str[i] < 16 ? "\\0" : "\\");
            my_putnbr_base(str[i], base);
        } else
            my_putchar(str[i]);
    }
    return (0);
}
