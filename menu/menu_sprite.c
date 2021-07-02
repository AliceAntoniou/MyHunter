/*
** EPITECH PROJECT, 2020
** duck_menu
** File description:
** init texts and window
*/

#include "duck_menu.h"

sfText *create_title(void);

sfSprite *create_buttons(void)
{
    sfIntRect cam_menu = {0, 0, 128, 256};
    sfVector2f pos = {342.5, 325};
    sfTexture *menu_t = sfTexture_createFromFile(
                    "textures/menu.png", &cam_menu);
    sfSprite *menu_s = sfSprite_create();

    sfSprite_setPosition(menu_s, pos);
    sfSprite_setTexture(menu_s, menu_t, 1);
    return (menu_s);
}

sfSprite *create_help(void)
{
    sfIntRect cam_help = {0, 0, 700, 500};
    sfVector2f pos = {56.5, 54.5};
    sfTexture *help_t = sfTexture_createFromFile(
                    "textures/help.png", &cam_help);
    sfSprite *help_s = sfSprite_create();

    sfSprite_setPosition(help_s, pos);
    sfSprite_setTexture(help_s, help_t, 1);
    return (help_s);
}

sfSprite *create_help_button(void)
{
    sfIntRect cam_help = {0, 0, 128, 64};
    sfVector2f pos = {685, 0};
    sfTexture *help_t = sfTexture_createFromFile(
                    "textures/help_button.png", &cam_help);
    sfSprite *help_s = sfSprite_create();

    sfSprite_setPosition(help_s, pos);
    sfSprite_setTexture(help_s, help_t, 1);
    return (help_s);
}

sprites_t *menu_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    sprites->background = create_background();
    sprites->buttons = create_buttons();
    sprites->title = create_title();
    sprites->help = create_help();
    sprites->help_button = create_help_button();
    return (sprites);
}