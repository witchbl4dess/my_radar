/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-radar-menzo.smit-adam
** File description:
** my.h
*/

#ifndef B_MUL_100_NCE_1_1_MYRADAR_MENZO_SMIT_ADAM_MY_H
    #define B_MUL_100_NCE_1_1_MYRADAR_MENZO_SMIT_ADAM_MY_H

    #include "stdio.h"
    #include "SFML/Graphics.h"

sfSprite *addBackground(sfRenderWindow *window, const char *imagePath);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_putchar(char c);
char **allocate_2d_array(int nb_rows, int nb_cols);
char **fill_2d_array(FILE *file, char **arr, int nb_rows, int nb_cols);

#endif //B_MUL_100_NCE_1_1_MYRADAR_MENZO_SMIT_ADAM_MY_H
