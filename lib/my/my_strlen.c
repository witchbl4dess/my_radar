/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Counts the number of characters in a string and return the result
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != 0; i++);
    return (i);
}
