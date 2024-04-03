/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Header file for my library
*/

#ifndef MY_H
    #define MY_H

    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define BINARY_B "01"
    #define OCTAL_B "01234567"
    #define DECIMAL_B "0123456789"
    #define HEXA_B_LOWER "0123456789abcdef"
    #define HEXA_B_UPPER "0123456789ABCDEF"
    #include <stdlib.h>
    #include <stdio.h>
    #define SS_INT signed char
    #define USS_INT char

typedef enum my_bool {
    _FALSE,
    _TRUE
} _bool;

typedef struct float_arithmetic {
    SS_INT sign : 1;
    short exponant : 11;
    long fraction : 52;
} flt_ar;

void my_putchar(char c);
int my_isneg(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
int my_putnbr_base(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
char *my_strdup(char const *str);

#endif /* MY_H */
