/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** init structs
*/

#include "duck_hunt.h"

difficulty_t *set_dificulty(void)
{
    difficulty_t *diff = malloc(sizeof(difficulty_t));

    diff->duck_speed = 3;
    diff->child_speed = 5;
    diff->step = 1;
    return (diff);
}