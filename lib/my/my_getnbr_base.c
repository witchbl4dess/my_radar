/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Returns a number sent to the function as a string
*/

static int const MAX_INT = 2147483647;
static int const MIN_INT = -2147483648;

static int is_digit(char c, char const *base)
{
    for (int i = 0; base[i] != 0; i++)
        if (base[i] == c)
            return (i);
    return (-1);
}

static int find_sign(char const *str, int max)
{
    int nb = 0;

    for (int i = max; i >= 0; i--) {
        if (str[i] == '-' || str[i] == '+')
            nb = str[i] == '-' ? nb + 1 : nb;
        else
            break;
    }
    return (nb % 2);
}

static int convert(char const *str, int i, int j, char const *b)
{
    char iso[j - i];
    int k = 0;
    int result = 0;
    int neg = find_sign(str, i - 1);
    int len = 0;

    for (; b[len] != 0; len++);
    for (; k + i < j; k++)
        iso[k] = str[i + k];
    iso[k] = 0;
    k = 0;
    for (; iso[k] != 0; k++) {
        result = result * len;
        result = result + (neg ? -(is_digit(iso[k], b)) : is_digit(iso[k], b));
        if ((result > 0 && neg) || (result < 0 && !neg))
            return (0);
    }
    return (result);
}

int my_getnbr_base(char const *str, char const *base)
{
    int i = 0;
    int j;

    for (; is_digit(str[i], base) == -1 && str[i] != 0; i++);
    if (str[i] == 0)
        return (0);
    j = i;
    for (; is_digit(str[j], base) != -1 && str[j] != 0; j++);
    return (convert(str, i, j, base));
}
