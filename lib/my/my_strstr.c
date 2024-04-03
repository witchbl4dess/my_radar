/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Find the first occurence of to_find in str
*/
#include <stddef.h>

static int a_in_b(char *str, char const *to_find, int begin)
{
    for (int i = 0; to_find[i] != 0; i++) {
        if (str[begin + i] != to_find[i])
            return (0);
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    if (str[0] == 0 || to_find[0] == 0)
        return (NULL);
    for (; str[i] != to_find[0]; i++) {
        if (str[i] == 0)
            return (NULL);
    }
    if (a_in_b(str, to_find, i))
        return (str + i);
    else
        return (my_strstr(str + i + 1, to_find));
}
