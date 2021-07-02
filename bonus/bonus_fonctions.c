/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** bonus fonctions
*/

#include "duck_hunt.h"

int move_sprite_zqsd(duck_t *ducks)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        ducks->vector.x = 0;
        ducks->vector.y = -5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        ducks->vector.x = -5;
        ducks->vector.y = 0;
        sfSprite_setTexture(ducks->sprite, ducks->texture_left, 1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        ducks->vector.x = 0;
        ducks->vector.y = 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        ducks->vector.x = 5;
        ducks->vector.y = 0;
        sfSprite_setTexture(ducks->sprite, ducks->texture_right, 1);
    }
}

int wave_move_sprite(sfVector2f *vector, sfSprite *sprite, int *time)
{
    *time += 1;
    vector->x = 3;
    if (*time < 0) {
        vector->y += 1;
        return (0);
    }
    if (*time >= 0 && *time < 5) {
        vector->y -= 1;
        return (0);
    }
    *time = -6;
}