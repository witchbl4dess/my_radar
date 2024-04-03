/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** create_tower.c
*/

#include "../../../../include/radar.h"
#include "stdio.h"

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}

sfCircleShape *circle_log(sfVector2f pos, int radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setOutlineColor(circle, sfMagenta);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    return circle;
}

void create_tower(node_tower **tower, char **ligne, sfTexture *texture)
{
    *tower = malloc(sizeof(node_tower));
    (*tower)->position.x = my_atoi(ligne[1]);
    (*tower)->position.y = my_atoi(ligne[2]);
    (*tower)->radius = my_atoi(ligne[3]) * WIDTH / 100;
    (*tower)->is_active_circle = true;
    (*tower)->is_visible = true;
    (*tower)->sprite = sfSprite_create();
    sfSprite_setTexture((*tower)->sprite, texture, sfTrue);
    sfSprite_setPosition((*tower)->sprite, (*tower)->position);
    sfSprite_setOrigin((*tower)->sprite, (sfVector2f){25, 25});
    (*tower)->circle = circle_log((*tower)->position, (*tower)->radius);
    (*tower)->next = NULL;
}

void setup_tower(list_tower *li, char **argv, int argc)
{
    node_tower *tower;
    sfTexture *texture = sfTexture_createFromFile(
            "./radar/src/assets/png/tower1.png", NULL);
    char **ligne;
    int rowslen = rows_len(argv[1]);
    int colslen = cols_len(argv[1]);
    char **tower_info = load_2d_arr_from_file(argv[1], rowslen, colslen);

    for (int i = 0; i < rowslen; i++) {
        ligne = my_str_to_word_array(tower_info[i]);
        if (ligne[0][0] == 'T') {
            create_tower(&tower, ligne, texture);
            tower->next = li->head;
            li->head = tower;
        }
    }
}
