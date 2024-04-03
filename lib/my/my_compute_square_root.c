/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** Returns the square root of the number passed as parameter
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    for (; result * result < nb; result++);
    if (result * result == nb)
        return (result);
    return (0);
}
