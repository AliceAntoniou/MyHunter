/*
** EPITECH PROJECT, 2020
** duck_menu
** File description:
** init sprite
*/

#include "duck_menu.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {813, 609, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                    "Hunter", sfClose, NULL);
    sfVector2i mpos = {140, 500};

    sfRenderWindow_setPosition(window, mpos);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

sfText *create_title(void)
{
    sfText *title = sfText_create();
    sfVector2f tpos = {162, 120};
    sfFont *font = sfFont_createFromFile("textures/title.ttf");

    sfText_setFont(title, font);
    sfText_setCharacterSize(title, 100);
    sfText_setPosition(title, tpos);
    sfText_setFillColor(title, sfBlack);
    sfText_setString(title, "Duck Hunt");
    return (title);
}