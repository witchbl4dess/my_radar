/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Reverse the string passed as parameter
*/

char *my_revstr(char *str)
{
    int len = 0;
    int i;
    char c;

    for (; str[len]; len++);
    for (i = 0; str[i + i - len % 2]; i++) {
        c = str[i];
        *(str + i) = str[len - i - 1];
        *(str + len - i - 1) = c;
    }
    return (str);
}
