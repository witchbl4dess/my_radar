/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** create_plane.c
*/

#include <SFML/Graphics.h>
#include "../../../../include/radar.h"

void draw_planes(window_t *window, plane_list_t *planes)
{
    node_plane *tmp = planes->head;

    while (tmp != NULL) {
        if (!tmp->depart) {
            tmp = tmp->next;
            continue;
        }
        if (tmp->is_active_rect) {
            sfRenderWindow_drawRectangleShape(window->window, tmp->rect, NULL);
        }
        if (tmp->is_visible) {
            sfRenderWindow_drawSprite(window->window, tmp->sprite, NULL);
        }
        tmp = tmp->next;
    }
}

void move_planes(node_plane *pl)
{
    float x = pl->posarrival.x - pl->posdeparture.x;
    float y = pl->posarrival.y - pl->posdeparture.y;
    float distance = sqrt(pow(x, 2) + pow(y, 2));
    float x_unit_vector = x / distance;
    float y_unit_vector = y / distance;

    pl->position.x += x_unit_vector * pl->speed * 0.01;
    pl->position.y += y_unit_vector * pl->speed * 0.01;
    sfSprite_setPosition(pl->sprite, pl->position);
    sfRectangleShape_setPosition(pl->rect, pl->position);
}

int condition(node_plane *tmp, float seconds)
{
    if (tmp->delay <= seconds) {
        tmp->depart = true;
        move_planes(tmp);
    }
}

void septemberplane(plane_list_t *planes, sfClock *clock1, sfClock *clock2)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock2));
    node_plane *tmp = planes->head;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock1)) > 0.01) {
        while (tmp != NULL) {
            condition(tmp, seconds);
            tmp = tmp->next;
        }
        sfClock_restart(clock1);
    }
}
