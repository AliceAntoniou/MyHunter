/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** var creation
*/

#include "duck_hunt.h"

sfSound *create_sound(char *soundfile)
{
    sfSoundBuffer *coin = sfSoundBuffer_createFromFile(soundfile);
    sfSound *coin_s = sfSound_create();

    sfSound_setBuffer(coin_s, coin);
    return (coin_s);
}

sfText *create_score(void)
{
    sfText *scoret = sfText_create();
    sfVector2f tpos = {675, 535};
    sfFont *font = sfFont_createFromFile("textures/score.ttf");

    sfText_setFont(scoret, font);
    sfText_setCharacterSize(scoret, 30);
    sfText_setPosition(scoret, tpos);
    sfText_setFillColor(scoret, sfBlack);
    return (scoret);
}

sfText *create_combo(void)
{
    sfText *combo = sfText_create();
    sfVector2f tpos = {755, 540};
    sfFont *font = sfFont_createFromFile("textures/combo.TTF");

    sfText_setFont(combo, font);
    sfText_setCharacterSize(combo, 40);
    sfText_setPosition(combo, tpos);
    sfText_setFillColor(combo, sfBlack);
    sfText_setRotation(combo, 20);
    return (combo);
}

sfText *create_kill(void)
{
    sfText *killt = sfText_create();
    sfVector2f tpos = {100, 535};
    sfFont *font = sfFont_createFromFile("textures/score.ttf");

    sfText_setFont(killt, font);
    sfText_setCharacterSize(killt, 30);
    sfText_setPosition(killt, tpos);
    sfText_setFillColor(killt, sfBlack);
    return (killt);
}