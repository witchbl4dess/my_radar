/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** load.c
*/

#include "stdio.h"
#include "stdlib.h"
#include "../../../../include/my.h"

char **allocate_2d_array(int nb_rows, int nb_cols)
{
    char **arr = (char **)malloc(nb_rows * sizeof(char *));

    if (arr == NULL)
        return NULL;
    for (int i = 0; i < nb_rows; ++i) {
        arr[i] = (char *)malloc((nb_cols + 1) * sizeof(char));
    }
    return arr;
}

char **fill_2d_array(FILE *file, char **arr, int nb_rows, int nb_cols)
{
    int row = 0;
    int col = 0;
    char ch;

    while (fread(&ch, sizeof(char), 1, file) == 1 && row < nb_rows) {
        if (ch != '\n' && col < nb_cols) {
            arr[row][col] = ch;
            col++;
        }
        if (!(ch != '\n' && col - 1 < nb_cols) && ch == '\n') {
            arr[row][col] = '\0';
            col = 0;
            ++row;
        }
    }
    return arr;
}

char **load_2d_arr_from_file(const char *filepath, int nb_rows, int nb_cols)
{
    FILE *file = fopen(filepath, "r");
    char **arr = allocate_2d_array(nb_rows, nb_cols);

    arr = fill_2d_array(file, arr, nb_rows, nb_cols);
    fclose(file);
    return arr;
}
