/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** kill sprites fonctions
*/

#include "duck_hunt.h"

int kill_duck(sfRenderWindow *window, main_t *main)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f spos;
    sfIntRect rec = {110, 0, 110, 110};
    duck_l *tmp = main->ducks;

    for (int i = 0; i < INTS->duck_nbr; i++) {
        spos = sfSprite_getPosition(tmp->duck->sprite);
        if (DUCK_HITBOX_X && DUCK_HITBOX_Y) {
            add_shoted(&main->shoteds, create_shoted(
                        tmp->duck->sprite, rec, "textures/duck_left.png"));
            delete_duck(&main->ducks, i);
            INTS->kills++;
            INTS->shoted_nbr++;
            INTS->duck_nbr--;
            INTS->combo++;
            if (tmp->duck->color == 1) {
                INTS->kills += 2;
                INTS->score += 95 * INTS->combo;
            }
            INTS->score += 5 * INTS->combo;
            return (0);
        } else
            tmp = tmp->next;
    }
    return (0);
}

int kill_child(sfRenderWindow *window, main_t *main)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f spos;
    sfIntRect rec = {45, 0, 45, 45};
    child_l *tmp = main->child;

    for (int i = 0; i < INTS->child_nbr; i++) {
        spos = sfSprite_getPosition(tmp->child->sprite);
        if (CHILD_HITBOX_X && CHILD_HITBOX_Y) {
            add_shoted(&main->shoteds, create_shoted(
                    tmp->child->sprite, rec, "textures/Child_Right.png"));
            delete_child(&main->child, i);
            INTS->shoted_nbr++;
            INTS->child_nbr--;
            INTS->combo = 0;
            INTS->score -= 100;
            return (0);
        } else
            tmp = tmp->next;
    }
    return (0);
}

int kill_mole(sfRenderWindow *window, main_t *main)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f spos = sfSprite_getPosition(MOLE->sprite);
    sfIntRect rec = {71, 0, 64, 64};

    if (MOLE_HITBOX_X && MOLE_HITBOX_Y) {
        add_shoted(&main->shoteds, create_shoted(
                MOLE->sprite, rec, "textures/Taupe.png"));
        MOLE->pos.x = -200;
        sfSprite_setPosition(MOLE->sprite, spos);
        INTS->shoted_nbr++;
        INTS->combo++;
        INTS->kills += 2;
        INTS->score += 300;
        return (1);
    }
    return (0);
}

int while_focus(main_t *main, sfRenderWindow *window)
{
    int combo = 0;
    sfVector2f cam_shake = {-3, -3};

    if (sfMouse_isButtonPressed(sfMouseLeft) && sfTime_asSeconds(
                    sfClock_getElapsedTime(main->sounds->reload)) > 1) {
        sfSound_play(main->sounds->shotgun);
        sfSprite_move(main->sprites->background, cam_shake);
        INTS->kills--;
        if (INTS->combo > 9)
            INTS->combo = 9;
        combo = INTS->combo;
        kill_mole(window, main);
        kill_duck(window, main);
        kill_child(window, main);
        if (INTS->combo <= combo)
            INTS->combo = 0;
        sfClock_restart(main->sounds->reload);
    }
    return (0);
}