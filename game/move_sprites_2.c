/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** move sprites 2
*/

#include "duck_hunt.h"

static int mole_sate(main_t *main)
{
    if (MOLE->state == 0) {
        MOLE->rect.top = 131;
        MOLE->rect.left = 0;
    }
    if (MOLE->state == 12) {
        MOLE->rect.top = 71;
        MOLE->rect.left = 0;
    }
    if (MOLE->state == 6) {
        MOLE->rect.top = 3;
        MOLE->rect.left = 0;
    }
    if (MOLE->state == 18) {
        MOLE->state == -1;
        MOLE->pos.x = -200;
        MOLE->rect.top = 131;
        MOLE->rect.left = 0;
        sfSprite_setPosition(MOLE->sprite, MOLE->pos);
    }
}

int anim_mole(main_t *main)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
                (MOLE->frame)) > 200 && MOLE->state >= 0) {
        move_rect(&MOLE->rect, 64, 384);
        sfClock_restart(MOLE->frame);
        sfSprite_setPosition(MOLE->sprite, MOLE->pos);
        MOLE->state++;
    }
    mole_sate(main);
}

int sight_sprite(sfRenderWindow *window, sfSprite *sight)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f spos = {mpos.x - 32, mpos.y - 32};

    if (sfRenderWindow_hasFocus(window)) {
        sfSprite_setPosition(sight, spos);
        sfRenderWindow_drawSprite(window, sight, NULL);
    }
}