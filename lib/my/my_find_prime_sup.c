/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** Finds the closest prime number above the give number
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (!my_is_prime(i))
        i++;
    return (i);
}
