/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** collision.c
*/

#include <SFML/Graphics.h>
#include "../../../../include/radar.h"

void planefucker(node_plane *plane, plane_list_t *planes)
{
    node_plane *prev = NULL;
    node_plane *tmp = planes->head;

    while (tmp != NULL && tmp != plane) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        return;
    }
    if (prev == NULL) {
        planes->head = plane->next;
    } else {
        prev->next = plane->next;
    }
}

void handle_collision(node_plane *plane, node_plane *other_plane,
    plane_list_t *planes)
{
    if (plane != other_plane && plane->position.x >=
    other_plane->position.x - 20
        && plane->position.x <= other_plane->position.x + 20 &&
        plane->position.y >= other_plane->position.y - 20 &&
        plane->position.y <= other_plane->position.y + 20) {
        planefucker(other_plane, planes);
        planefucker(plane, planes);
    }
}

void handle_plane_collisions(node_plane *plane, node_plane *plane2,
    plane_list_t *planes)
{
    while (plane2 != NULL) {
        if (plane2->protection == true) {
            plane2 = plane2->next;
            continue;
        }
        handle_collision(plane, plane2, planes);
        plane2 = plane2->next;
    }
}

void collisioninter(plane_list_t *planes)
{
    node_plane *plane = planes->head;
    node_plane *plane2;

    while (plane != NULL) {
        plane2 = planes->head;
        if (plane->protection == true) {
            plane = plane->next;
            continue;
        }
        handle_plane_collisions(plane, plane2, planes);
        plane = plane->next;
    }
}

void colision(plane_list_t *planes, list_tower *listower)
{
    node_plane *plane = planes->head;
    node_tower *tower;

    while (plane != NULL) {
        tower = listower->head;
        while (tower != NULL) {
            handle_tower_collision(plane, tower);
            tower = tower->next;
        }
        plane = plane->next;
    }
}
