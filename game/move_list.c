/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** gest list move
*/

#include "duck_hunt.h"

int move_ducks(main_t *main, sfRenderWindow *window)
{
    duck_l *tmp = main->ducks;

    for (int i = 0; i < main->ints->duck_nbr; i++) {
        move_a_duck(tmp->duck, main->difficulty);
        sfSprite_setTextureRect(tmp->duck->sprite, tmp->duck->frame_cam);
        sfRenderWindow_drawSprite(window, tmp->duck->sprite, NULL);
        tmp = tmp->next;
    }
}

int move_child(child_l *childs, int child_nbr, sfRenderWindow *window)
{
    child_l *tmp = childs;

    for (int i = 0; i < child_nbr; i++) {
        sfSprite_move(tmp->child->sprite, tmp->child->vector);
        sfRenderWindow_drawSprite(window, tmp->child->sprite, NULL);
        tmp = tmp->next;
    }
}

int move_shoted(shoted_l *shoteds, int shoted_nbr, sfRenderWindow *window)
{
    shoted_l *tmp = shoteds;

    for (int i = 0; i < shoted_nbr; i++) {
        tmp->shoted->vector.y += 0.5;
        sfSprite_move(tmp->shoted->sprite, tmp->shoted->vector);
        sfRenderWindow_drawSprite(window, tmp->shoted->sprite, NULL);
        tmp = tmp->next;
    }
}