/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** functoin.c
*/

#include <SFML/Graphics.h>
#include "../../../../include/radar.h"

void handle_tower_collision(node_plane *plane, node_tower *tower)
{
    if (plane->position.x >= tower->position.x - tower->radius &&
        plane->position.x <= tower->position.x + tower->radius &&
        plane->position.y >= tower->position.y - tower->radius &&
        plane->position.y <= tower->position.y + tower->radius) {
        plane->protection = true;
        sfRectangleShape_setOutlineColor(plane->rect, sfGreen);
    }
}
