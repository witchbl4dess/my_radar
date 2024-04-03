/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** concatenate 2 strings up to n char
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != 0; i++);
    for (; src[j] != 0 && j < nb; j++)
        dest[i + j] = src[j];
    dest[i + j] = 0;
    return (dest);
}
