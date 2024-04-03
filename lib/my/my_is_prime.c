/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** returns 1 if the number is prime 0 otherwise
*/

int my_is_prime(int nb)
{
    int i = 1;

    if (nb < 2)
        return (0);
    for (; i * i <= nb; i++);
    for (int j = 1; j < i; j++) {
        if (my_is_prime(j) && nb % j == 0)
            return (0);
    }
    return (1);
}
