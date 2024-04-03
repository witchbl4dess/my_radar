/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-radar-menzo.smit-adam
** File description:
** radar.c
*/

#include "../../include/radar.h"
#include "../../include/my.h"

void redirecter(plane_list_t *planes)
{
    node_plane *plane = planes->head;

    while (plane != NULL) {
        plane->protection = false;
        sfRectangleShape_setOutlineColor(plane->rect, sfRed);
        plane = plane->next;
    }
}

int gameloop(window_t *window, sfSprite *backgroundSprite, plane_list_t planes,
    list_tower listower)
{
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();

    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &(window->event))) {
            toggleevent(window->event, window->window, &planes, &listower);
        }
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, backgroundSprite, NULL);
        draw_tower(window, &listower);
        draw_planes(window, &planes);
        septemberplane(&planes, clock, clock2);
        redirecter(&planes);
        colision(&planes, &listower);
        collisioninter(&planes);
        sfRenderWindow_display(window->window);
    }
}

int main(int argc, char **argv)
{
    window_t *window = create_window();
    sfTexture *backgroundTexture;
    sfSprite *backgroundSprite;
    plane_list_t planes = {NULL};
    list_tower listower = {NULL};
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();

    if (!check_args(argc, argv)) {
        return 84;
    }
    setup_tower(&listower, argv, argc);
    setup_planes(&planes, argv, argc);
    load_bg(&backgroundTexture, &backgroundSprite);
    gameloop(window, backgroundSprite, planes, listower);
    sfTexture_destroy(backgroundTexture);
    sfSprite_destroy(backgroundSprite);
    destroy_window(window);
    return EXIT_SUCCESS;
}
