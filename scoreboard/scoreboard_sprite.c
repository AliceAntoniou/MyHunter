/*
** EPITECH PROJECT, 2020
** duck_menu
** File description:
** init texts and window
*/

#include "scoreboard.h"

sfSprite *create_game_over(void)
{
    sfIntRect cam_game_over = {0, 0, 256, 256};
    sfVector2f pos = {278.5, 0};
    sfTexture *game_over_t = sfTexture_createFromFile(
                    "textures/game_over.png", &cam_game_over);
    sfSprite *game_over_s = sfSprite_create();

    sfSprite_setPosition(game_over_s, pos);
    sfSprite_setTexture(game_over_s, game_over_t, 1);
    return (game_over_s);
}

sfSprite *create_back_to_menu(void)
{
    sfIntRect cam_back_to_menu = {0, 96, 128, 64};
    sfVector2f pos = {342.5, 539};
    sfTexture *back_to_menu_t = sfTexture_createFromFile(
                    "textures/pause_menu.png", &cam_back_to_menu);
    sfSprite *back_to_menu_s = sfSprite_create();

    sfSprite_setPosition(back_to_menu_s, pos);
    sfSprite_setTexture(back_to_menu_s, back_to_menu_t, 1);
    return (back_to_menu_s);
}

sfText *create_score_over(void)
{
    sfText *scoret = sfText_create();
    sfVector2f tpos = {400, 260};
    sfFont *font = sfFont_createFromFile("textures/score.ttf");

    sfText_setFont(scoret, font);
    sfText_setCharacterSize(scoret, 30);
    sfText_setPosition(scoret, tpos);
    sfText_setFillColor(scoret, sfWhite);
    return (scoret);
}

sfText *create_scoreboard(void)
{
    sfText *scoret = sfText_create();
    sfVector2f tpos = {400, 330};
    sfFont *font = sfFont_createFromFile("textures/score.ttf");

    sfText_setFont(scoret, font);
    sfText_setCharacterSize(scoret, 30);
    sfText_setPosition(scoret, tpos);
    sfText_setFillColor(scoret, sfWhite);
    return (scoret);
}

sprites_t *game_over_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    sprites->game_over = create_game_over();
    sprites->back_to_menu = create_back_to_menu();
    sprites->score = create_score_over();
    sprites->scoreboard = create_scoreboard();
    return (sprites);
}