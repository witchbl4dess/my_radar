/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Displays the string passed as parameter
*/
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(1, (str + i), 1);
        i++;
    }
    return (i);
}
