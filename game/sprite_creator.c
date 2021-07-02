/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** sprites creator fonctions
*/

#include "duck_hunt.h"

sfSprite *create_pause_button(void)
{
    sfIntRect cam_pause = {0, 0, 64, 64};
    sfVector2f pos = {749, 0};
    sfTexture *pause_t = sfTexture_createFromFile(
                    "textures/pause_button.png", &cam_pause);
    sfSprite *pause_s = sfSprite_create();

    sfSprite_setPosition(pause_s, pos);
    sfSprite_setTexture(pause_s, pause_t, 1);
    return (pause_s);
}

sfSprite *create_bush(int x, int y)
{
    sfIntRect cam_bush = {0, 0, 128, 128};
    sfVector2f pos = {x, y};
    sfTexture *bush_t = sfTexture_createFromFile(
                    "textures/bush.png", &cam_bush);
    sfSprite *bush_s = sfSprite_create();

    sfSprite_setPosition(bush_s, pos);
    sfSprite_setTexture(bush_s, bush_t, 1);
    return (bush_s);
}

sfSprite *create_duck_count(void)
{
    sfIntRect cam_chiken = {0, 0, 64, 100};
    sfVector2f pos = {120, 540};
    sfVector2f scale = {0.5, 0.5};
    sfTexture *chiken_t = sfTexture_createFromFile(
                    "textures/shotgun_bullets.png", &cam_chiken);
    sfSprite *chiken_s = sfSprite_create();

    sfSprite_setScale(chiken_s, scale);
    sfSprite_setPosition(chiken_s, pos);
    sfSprite_setTexture(chiken_s, chiken_t, 1);
    return (chiken_s);
}

sfSprite *create_menu(void)
{
    sfIntRect cam_menu = {0, 0, 128, 256};
    sfVector2f pos = {342.5, 176.5};
    sfTexture *menu_t = sfTexture_createFromFile(
                    "textures/pause_menu.png", &cam_menu);
    sfSprite *menu_s = sfSprite_create();

    sfSprite_setPosition(menu_s, pos);
    sfSprite_setTexture(menu_s, menu_t, 1);
    return (menu_s);
}

sfSprite *create_sight(void)
{
    sfIntRect cam_sight = {0, 0, 16, 16};
    sfVector2f pos = {249, 202};
    sfVector2f scale = {3.9, 3.9};
    sfTexture *sight_t = sfTexture_createFromFile(
                    "textures/sight.png", &cam_sight);
    sfSprite *sight_s = sfSprite_create();

    sfSprite_setPosition(sight_s, pos);
    sfSprite_setTexture(sight_s, sight_t, 1);
    sfSprite_setScale(sight_s, scale);
    return (sight_s);
}