/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** calc_len.c
*/
#include "stdlib.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void read_file(char *filepath, char *buffer, int size)
{
    int fd = open(filepath, O_RDONLY);
    ssize_t bytes_read = read(fd, buffer, size);

    buffer[bytes_read] = '\0';
    close(fd);
}

int rows_len(const char *filepath)
{
    int lines = 0;
    char buffer[80000];
    FILE *file = fopen(filepath, "r");
    size_t bytes_read;

    if (file == NULL) {
        return -1;
    }
    lines = 0;
    buffer[80000];
    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (bytes_read <= 0)
        return 0;
    for (size_t i = 0; i < bytes_read; ++i) {
        if (buffer[i] == '\n')
            lines++;
    }
    fclose(file);
    return lines;
}

void cols_lencond(char *buffer, int i, int *cols, int *max_cols)
{
    if (buffer[i] != '\n')
        *cols += 1;
    if (buffer[i] == '\n' && *cols > *max_cols)
        *max_cols = *cols;
    if (buffer[i] == '\n')
        *cols = 0;
}

int cols_len(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    int cols = 0;
    int max_cols = 0;
    char buffer[1024];
    size_t bytes_read;

    if (file == NULL) {
        return -1;
    }
    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (bytes_read <= 0)
        return 0;
    for (size_t i = 0; i < bytes_read; ++i) {
        cols_lencond(buffer, i, &cols, &max_cols);
    }
    fclose(file);
    return max_cols;
}
