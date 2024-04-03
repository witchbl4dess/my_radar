/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** create_tower.c
*/

#include "../../../../include/radar.h"
#include "stdio.h"

void key_s(sfEvent event, sfRenderWindow *window, plane_list_t *planes,
    list_tower *li)
{
    node_tower *tmp = li->head;
    node_plane *tmp2 = planes->head;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        while (tmp != NULL) {
            tmp->is_visible = !tmp->is_visible;
            tmp = tmp->next;
        }
        while (tmp2 != NULL) {
            tmp2->is_visible = !tmp2->is_visible;
            tmp2 = tmp2->next;
        }
    }
}

void toggleevent(sfEvent event, sfRenderWindow *window, plane_list_t *planes,
    list_tower *li)
{
    node_tower *tmp = li->head;
    node_plane *tmp2 = planes->head;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL) {
        while (tmp != NULL) {
            tmp->is_active_circle = !tmp->is_active_circle;
            tmp = tmp->next;
        }
        while (tmp2 != NULL) {
            tmp2->is_active_rect = !tmp2->is_active_rect;
            tmp2 = tmp2->next;
        }
    }
    key_s(event, window, planes, li);
}

void draw_tower(window_t *window, list_tower *li)
{
    node_tower *tmp = li->head;

    while (tmp != NULL) {
        if (tmp->is_active_circle) {
            sfRenderWindow_drawCircleShape(window->window, tmp->circle, NULL);
        }
        if (tmp->is_visible) {
            sfRenderWindow_drawSprite(window->window, tmp->sprite, NULL);
        }
        tmp = tmp->next;
    }
}
