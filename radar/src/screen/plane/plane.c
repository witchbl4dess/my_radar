/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** init_plane.c
*/

#include <SFML/Graphics.h>
#include "../../../../include/radar.h"

sfRectangleShape *recter(sfVector2f position)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect, 2);
    return rect;
}

void create_plane(node_plane **plane, char **ligne, sfTexture *texture)
{
    *plane = malloc(sizeof(node_plane));
    (*plane)->posdeparture.x = my_atoi(ligne[1]);
    (*plane)->posdeparture.y = my_atoi(ligne[2]);
    (*plane)->posarrival.x = my_atoi(ligne[3]);
    (*plane)->posarrival.y = my_atoi(ligne[4]);
    (*plane)->position = (*plane)->posdeparture;
    (*plane)->speed = my_atoi(ligne[5]);
    (*plane)->delay = my_atoi(ligne[6]);
    (*plane)->is_active_rect = true;
    (*plane)->is_visible = true;
    (*plane)->depart = false;
    (*plane)->sprite = sfSprite_create();
    sfSprite_setTexture((*plane)->sprite, texture, sfTrue);
    sfSprite_setPosition((*plane)->sprite, (*plane)->position);
    (*plane)->rect = recter((*plane)->position);
    (*plane)->next = NULL;
}

void setup_planes(plane_list_t *li, char **argv, int argc)
{
    node_plane *plane;
    sfTexture *texture = sfTexture_createFromFile(
            "./radar/src/assets/png/plane1.png", NULL);
    char **ligne;
    int rowslen = rows_len(argv[1]);
    int colslen = cols_len(argv[1]);
    char **plane_info = load_2d_arr_from_file(argv[1], rowslen, colslen);

    for (int i = 0; i < rowslen; i++) {
        ligne = my_str_to_word_array(plane_info[i]);
        if (ligne[0][0] == 'A') {
            create_plane(&plane, ligne, texture);
            plane->next = li->head;
            li->head = plane;
        }
    }
}
