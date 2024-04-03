/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** Checks if the string contains only digits
*/

int my_str_isnum(char const *str)
{
    if (*str == 0)
        return (1);
    for (int i = 0; str[i] != 0; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}
