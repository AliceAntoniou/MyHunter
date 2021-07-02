/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** sprites creator fonctions
*/

#include "duck_hunt.h"

sfSprite *create_background(void)
{
    sfIntRect cam_background = {0, 0, 626, 469};
    sfVector2f scale = {1.3, 1.3};
    sfTexture *background_t = sfTexture_createFromFile(
                    "textures/backgroud.jpg", &cam_background);
    sfSprite *background_s = sfSprite_create();

    sfSprite_setTexture(background_s, background_t, 1);
    sfSprite_setScale(background_s, scale);
    return (background_s);
}