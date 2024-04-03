/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** usage.c
*/

#include "../../include/radar.h"
#include "../../include/my.h"

void display_usage(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("\n");
    my_putstr("USAGE\n");
    my_putstr("    ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("    path_to_script    The path to the script file.\n");
    my_putstr("\n");
    my_putstr("OPTIONS\n");
    my_putstr("    -h                print the usage and quit.\n");
    my_putstr("\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("    'L' key        enable/disable hitboxes and areas.\n");
    my_putstr("    'S' key        enable/disable sprites.\n");
}

int check_args(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    if (ac == 2 && my_strcmp(av[1], "-d") == 0) {
        return 1;
    }
    if (ac != 2) {
        my_putstr("Invalid number of arguments.\n");
        return 0;
    }
    return 1;
}
