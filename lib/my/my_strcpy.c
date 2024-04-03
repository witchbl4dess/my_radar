/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** copies the string passed as parameter into the second one
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++) {
        *(dest + i) = src[i];
    }
    dest[i] = 0;
    return (dest);
}
