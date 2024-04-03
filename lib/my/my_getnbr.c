/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Returns a number sent to the function as a string
*/

static int const MAX_INT = 2147483647;
static int const MIN_INT = -2147483648;

static int is_digit(char c)
{
    if (c <= '9' && c >= '0')
        return (1);
    return (0);
}

static int convert(char const *str, int i, int j, int neg)
{
    char isolate[j - i];
    int k = 0;
    int result = 0;

    for (; k + i < j; k++)
        isolate[k] = str[i + k];
    isolate[k] = 0;
    k = 0;
    for (; isolate[k] != 0; k++) {
        result = result * 10;
        result = result + (neg ? -(isolate[k] - 48) : isolate[k] - 48);
        if ((result > 0 && neg) || (result < 0 && !neg))
            return (0);
    }
    return (result);
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

int my_getnbr(char const *str)
{
    int i = 0;
    int j;
    int neg = 0;

    for (; !is_digit(str[i]) && str[i] != 0; i++);
    if (str[i] == 0)
        return (0);
    j = i;
    for (; is_digit(str[j]) && str[j] != 0; j++);
    neg = find_sign(str, i - 1);
    return (convert(str, i, j, neg));
}
