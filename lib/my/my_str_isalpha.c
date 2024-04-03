/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** checks if a string is only alpha characters
*/

int my_str_isalpha(char const *str)
{
    if (*str == 0)
        return (1);
    for (int i = 0; str[i] != 0; i++)
        if (str[i] > 'Z' && str[i] < 'a' || str[i] < 'A' || str[i] > 'z')
            return (0);
    return (1);
}
