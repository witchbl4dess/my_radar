/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Compares the first and second strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int diff = 0;

    for (int i = 0; s1[i] != 0 || s2[i] != 0; i++) {
        if (s1[i] == 0)
            return (-1);
        if (s2[i] == 0)
            return (1);
        diff = diff + s1[i] - s2[i];
    }
    return (diff);
}
