/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** print the character passed as parameter
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_sputchar(char *str, char c)
{
    int index;

    for (; str[index] != 0; index++);
    str[index] = c;
    return (str);
}
