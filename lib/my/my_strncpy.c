/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** copies the src str to dest str with n bytes
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n || !src[i]; i++) {
        *(dest + i) = src[i];
    }
    if (!src[i] && i < n)
        *(dest + i) = 0;
}
