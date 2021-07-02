/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** stop game
*/

#include "duck_hunt.h"

int destroy_sounds(sound_t *sounds)
{
    sfSound_stop(sounds->shotgun);
    sfSound_destroy(sounds->shotgun);
    sfSound_stop(sounds->coin);
    sfSound_destroy(sounds->coin);
    sfClock_destroy(sounds->reload);
    free(sounds);
}

int destroy_sprites(sprites_t *sprites)
{
    sfSprite_destroy(sprites->pause);
    sfSprite_destroy(sprites->background);
    sfSprite_destroy(sprites->sight);
    sfSprite_destroy(sprites->bush_left);
    sfSprite_destroy(sprites->bush_right);
    sfSprite_destroy(sprites->duck_count);
    sfSprite_destroy(sprites->mole->sprite);
    sfClock_destroy(sprites->mole->frame);
    free(sprites->mole);
    free(sprites);
}

int destroy_texts(txt_t *texts)
{
    sfText_destroy(texts->score);
    sfText_destroy(texts->combo);
    sfText_destroy(texts->kills);
    free(texts);
}

int stop(main_t *main)
{
    for (int i = 0; i < INTS->duck_nbr; i++) {
        delete_duck(&main->ducks, 0);
    }
    for (int i = 0; i < INTS->child_nbr; i++) {
        delete_child(&main->child, 0);
    }
    for (int i = 0; i < INTS->shoted_nbr; i++) {
        delete_shoted(&main->shoteds, 0);
    }
    destroy_sounds(main->sounds);
    destroy_sprites(main->sprites);
    destroy_texts(main->texts);
    free(main->difficulty);
    sfClock_destroy(INTS->duck_time_passed);
    sfClock_destroy(INTS->child_time_passed);
    sfClock_destroy(INTS->mole_time_passed);
    free(INTS);
}