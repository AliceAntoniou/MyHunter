/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** init structs
*/

#include "duck_hunt.h"

difficulty_t *set_dificulty(void);

ints_t *init_ints(void)
{
    ints_t *ints = malloc(sizeof(ints_t));

    ints->duck_next_spawn = 1;
    ints->duck_time_passed = sfClock_create();
    ints->child_next_spawn = 10;
    ints->child_time_passed = sfClock_create();
    ints->mole_next_spawn = 30;
    ints->mole_time_passed = sfClock_create();
    ints->duck_nbr = 0;
    ints->child_nbr = 0;
    ints->shoted_nbr = 0;
    ints->score = 0;
    ints->combo = 0;
    ints->kills = 5;
    return (ints);
}

sound_t *init_sound(void)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->coin = create_sound("Sound/Coin.wav");
    sound->shotgun = create_sound("Sound/Shotgun.wav");
    sfSound_setVolume(sound->shotgun, 2.75);
    sound->reload = sfClock_create();
    return (sound);
}

sprites_t *init_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    sprites->background = create_background();
    sprites->pause = create_pause_button();
    sprites->sight = create_sight();
    sprites->mole = create_mole();
    sprites->bush_left = create_bush(142, 390);
    sprites->bush_right = create_bush(539, 390);
    sprites->duck_count = create_duck_count();
    return (sprites);
}

txt_t *init_txt(void)
{
    txt_t *txt = malloc(sizeof(txt_t));

    txt->combo = create_combo();
    txt->score = create_score();
    txt->kills = create_kill();
    return (txt);
}

main_t *init_main_struct(main_t *main)
{
    main->ducks = NULL;
    main->child = NULL;
    main->shoteds = NULL;
    main->ints = init_ints();
    main->sounds = init_sound();
    main->sprites = init_sprites();
    main->texts = init_txt();
    main->difficulty = set_dificulty();
    main->stop_game = 0;
    return (main);
}