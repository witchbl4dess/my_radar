/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** Duplicate the string and returns a pointer to the newly allocated string
*/
#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *new_str = (char *)malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = 0;
    return (new_str);
}
