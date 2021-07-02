/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** animals creation
*/

#include "duck_hunt.h"

duck_t *create_duck_2(duck_t *duck)
{
    sfIntRect duck_all = {0, 0, 330, 110};

    duck->texture_right = sfTexture_createFromFile(
                    "textures/duck_right.png", &duck_all);
    duck->texture_left = sfTexture_createFromFile(
                    "textures/duck_left.png", &duck_all);
    duck->frame = sfClock_create();
    duck->color = 0;
    sfSprite_setTexture(duck->sprite, duck->texture_right, 1);
    sfSprite_setTextureRect(duck->sprite, duck->frame_cam);
    return (duck);
}

child_t *create_child_2(int bool, child_t *child)
{
    sfIntRect child_all = {0, 0, 45, 45};

    if (bool == 0) {
        child->vector.x = 5;
        child->texture = sfTexture_createFromFile(
                    "textures/Child_Right.png", &child_all);
    }
    if (bool == 1) {
        child->vector.x = -5;
        child->texture = sfTexture_createFromFile(
                    "textures/Child_Left.png", &child_all);
    }
    sfSprite_setTexture(child->sprite, child->texture, 1);
    return (child);
}

mole_t *create_mole_2(mole_t *mole)
{
    sfIntRect rec_mole = {0, 0, 64, 64};

    mole->rect.top = 131;
    mole->rect.left = 0;
    mole->rect.width = 64;
    mole->rect.height = 64;
    sfSprite_setTextureRect(mole->sprite, rec_mole);
    return (mole);
}