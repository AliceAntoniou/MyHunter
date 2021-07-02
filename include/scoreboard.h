/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** scoreboard
*/

#ifndef DUCK_HUNT_SCOREBOARD
#define DUCK_HUNT_SCOREBOARD

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BACK_TO_MENU_Y  mpos.y > 539 && mpos.y < 603
#define BACK_TO_MENU_X  mpos.x > 342 && mpos.x < 470

typedef struct all_sprite
{
    sfText *score;
    sfSprite *game_over;
    sfSprite *back_to_menu;
    sfText *scoreboard;
} sprites_t;

typedef struct ints_var_structures
{
    sfClock *duck_time_passed;
    int duck_next_spawn;
    sfClock *child_time_passed;
    int child_next_spawn;
    sfClock *mole_time_passed;
    int mole_next_spawn;
    int duck_nbr;
    int child_nbr;
    int shoted_nbr;
    int score;
    int combo;
    int kills;
} ints_t;

typedef struct scorboard_int_structure
{
    int i;
    int k;
} score_int;

int is_having_to_close(sfRenderWindow *window, int bool);
sprites_t *game_over_sprites(void);
char *get_score(void);
int write_scoreboard(char *str, char *score);

#endif