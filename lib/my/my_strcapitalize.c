/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalize every word of the sentence
*/
#include "my.h"

char *my_strcapitalize(char *str)
{
    int diff = 'A' - 'a';

    my_strlowcase(str);
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            continue;
        if (i == 0)
            str[i] += diff;
        if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
            continue;
        if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            continue;
        if (str[i - 1] >= '0' && str[i - 1] <= '9')
            continue;
        str[i] += diff;
    }
    return (str);
}
