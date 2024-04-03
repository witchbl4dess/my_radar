/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-radar-menzo.smit-adam
** File description:
** screen.c
*/

#include <SFML/Graphics.h>
#include "../../../include/radar.h"

window_t *create_window()
{
    window_t *window = malloc(sizeof(window_t));

    window->width = WIDTH;
    window->height = HEIGHT;
    window->mode.width = window->width;
    window->mode.height = window->height;
    window->mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->mode, "my radar", sfClose,
        NULL);
    return window;
}

void destroy_window(window_t *window)
{
    if (window) {
        sfRenderWindow_destroy(window->window);
        free(window);
    }
}
