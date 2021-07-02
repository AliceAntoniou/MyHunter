/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** menu
*/

#ifndef DUCK_HUNT_MENU
#define DUCK_HUNT_MENU

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

#define QUIT_BUTTON_X   ipos.x > 342 && ipos.x < 471
#define QUIT_BUTTON_Y   ipos.y > 517 && ipos.y < 581
#define NEW_GAME_X      ipos.x > 342 && ipos.x < 471
#define NEW_GAME_Y      ipos.y > 421 && ipos.y < 485
#define CONTINUE_X      ipos.x > 342 && ipos.x < 471
#define CONTINUE_Y      ipos.y > 325 && ipos.y < 389
#define HELP_X          mpos.x > 685 && mpos.x < 813
#define HELP_Y          mpos.y > 0 && mpos.y < 64

int game(sfRenderWindow *window);
sfRenderWindow *create_window(void);

typedef struct all_sprite
{
    sfSprite *background;
    sfSprite *buttons;
    sfSprite *help_button;
    sfSprite *help;
    sfText *title;
} sprites_t;

sfSprite *create_background(void);
int is_having_to_close(sfRenderWindow *window, int bool);
sfSprite *create_menu(void);
sfRenderWindow *create_window(void);
sprites_t *menu_sprites(void);

#endif