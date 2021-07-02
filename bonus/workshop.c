/*
** EPITECH PROJECT, 2020
** Workshop
** File description:
** workshop
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {626, 469, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                    "Hunter", sfClose, NULL);
    sfVector2i mpos = {140, 500};

    sfRenderWindow_setPosition(window, mpos);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

int is_having_to_close(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
    }
    return (0);
}

sfSprite *create_background(void)
{
    sfIntRect cam_background = {0, 0, 626, 469};
    sfTexture *background_t = sfTexture_createFromFile(
                    "textures/backgroud.jpg", &cam_background);
    sfSprite *background_s = sfSprite_create();

    sfSprite_setTexture(background_s, background_t, 1);
    return (background_s);
}

sfSprite *create_pause_button(void)
{
    sfIntRect cam_pause = {0, 0, 64, 64};
    sfVector2f pos = {562, 0};
    sfTexture *pause_t = sfTexture_createFromFile(
                    "textures/pause_button.png", &cam_pause);
    sfSprite *pause_s = sfSprite_create();

    sfSprite_setPosition(pause_s, pos);
    sfSprite_setTexture(pause_s, pause_t, 1);
    return (pause_s);
}

int main(void)
{
    sfRenderWindow *window = create_window();
    sfSprite *pause = create_pause_button();

    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, pause, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(pause);
    sfRenderWindow_destroy(window);
    return (0);
}