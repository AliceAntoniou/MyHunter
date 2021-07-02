/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** free structs in lists
*/

#include "duck_hunt.h"

int free_duck(duck_l *ducks)
{
    sfSprite_destroy(ducks->duck->sprite);
    sfTexture_destroy(ducks->duck->texture_left);
    sfTexture_destroy(ducks->duck->texture_right);
    sfClock_destroy(ducks->duck->frame);
    free(ducks->duck);
}

int free_child(child_l *childs)
{
    sfSprite_destroy(childs->child->sprite);
    sfTexture_destroy(childs->child->texture);
    free(childs->child);
}

int free_death(shoted_l *shoteds)
{
    sfSprite_destroy(shoteds->shoted->sprite);
    sfTexture_destroy(shoteds->shoted->texture);
    sfClock_destroy(shoteds->shoted->time);
    free(shoteds->shoted);
}