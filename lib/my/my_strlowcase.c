/*
** EPITECH PROJECT, 2023
** my_strlowercase.c
** File description:
** Puts every uppercase into lowercase letters
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] = str[i] - ('A' - 'a');
    }
    return (str);
}
