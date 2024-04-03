/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** compares the 2 strings up to n characters
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int diff = 0;
    int val1;
    int val2;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    for (int i = 0; i < n; i++) {
        val1 = i <= len1 ? s1[i] : 0;
        val2 = i <= len2 ? s2[i] : 0;
        diff += (val1 - val2);
    }
    return (diff);
}
