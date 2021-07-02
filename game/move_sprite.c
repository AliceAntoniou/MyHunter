/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** move sprites
*/

#include "duck_hunt.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left + rect->width > max_value) {
        rect->left = 0;
    }
}

static int dierctional_move(duck_t *ducks, int speed, int move)
{
    if (rand() % 8 == 1) {
        if (move == 0)
            ducks->vector.y = -speed;
        if (move == 1) {
            ducks->vector.x = -speed;
            sfSprite_setTexture(ducks->sprite, ducks->texture_left, 1);
        }
        if (move == 3)
            ducks->vector.y = speed;
        if (move == 2) {
            ducks->vector.x = speed;
            sfSprite_setTexture(ducks->sprite, ducks->texture_right, 1);
        }
    }
}

int move_sprite(duck_t *ducks, int speed)
{
    int move = rand() % 4;
    sfVector2f pos = sfSprite_getPosition(ducks->sprite);

    if (pos.y > 400) {
        ducks->vector.y = -1;
        move = rand() % 3;
    }
    dierctional_move(ducks, speed, move);
}

int move_a_duck(duck_t *duck, difficulty_t *diff)
{
    if (duck->color == 1) {
        sfSprite_setColor(duck->sprite, sfYellow);
        move_sprite(duck, diff->duck_speed * 2);
    } else
        move_sprite(duck, diff->duck_speed);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(duck->frame)) > 100) {
        move_rect(&duck->frame_cam, 110, 330);
        sfClock_restart(duck->frame);
    }
    sfSprite_move(duck->sprite, duck->vector);
    return (0);
}