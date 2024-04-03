/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** dist.c
*/

#include "../../../../lib/my/my.h"
#include "../../../../include/my.h"

#include <stdlib.h>

static int alpha_num(char c)
{
    if (((c < 'A' || c > 'z') || (c < 'a' && c > 'Z')) && (c < '0' || c > '9'))
        return (0);
    return (1);
}

char *get_word(char const *str, int *offset)
{
    int len = 0;
    char *new;
    int cp = *offset;

    for (; !alpha_num(str[cp]); cp++);
    for (; alpha_num(str[cp + len]); len++);
    new = (char *)malloc(sizeof(char) * (len + 1));
    new[len] = 0;
    for (int i = 0; i < len; i++) {
        new[i] = str[cp + i];
    }
    *offset = cp + len;
    return (new);
}

int count_sep(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (i == 0)
            continue;
        if (!alpha_num(str[i]) && alpha_num(str[i - 1]) && str[i + 1] != 0)
            nb++;
    }
    return (nb);
}

char **my_str_to_word_array(char *str)
{
    int nb = count_sep(str);
    int empty = str[0] == 0 ? 1 : 0;
    char **tab = (char **)malloc(sizeof(char *) * (nb + 2 - empty));
    int offset = 0;

    for (int i = 0; i < nb + 1 - empty; i++) {
        tab[i] = get_word(str, &offset);
    }
    tab[nb + 1 - empty] = NULL;
    return (tab);
}
