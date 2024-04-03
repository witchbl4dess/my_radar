/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCE-1-1-myradar-menzo.smit-adam
** File description:
** background.c
*/

#include <SFML/Graphics.h>
#include "../../../../include/radar.h"

void load_bg(sfTexture **btext, sfSprite **backgroundSprite)
{
    sfVector2u textureSize;
    float desiredWidth = 1920.0f;
    float desiredHeight = 1080.0f;
    float scaleX;
    float scaleY;

    *btext = sfTexture_createFromFile("./radar/src/assets/png/map.png", NULL);
    *backgroundSprite = sfSprite_create();
    sfSprite_setTexture(*backgroundSprite, *btext, sfTrue);
    textureSize = sfTexture_getSize(*btext);
    scaleX = desiredWidth / textureSize.x;
    scaleY = desiredHeight / textureSize.y;
    sfSprite_setScale(*backgroundSprite, (sfVector2f){scaleX, scaleY});
}
