/*
** EPITECH PROJECT, 2020
** Duck Hunt
** File description:
** Structures and macros
*/

#ifndef DUCK_HUNT_GAME
#define DUCK_HUNT_GAME

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>



#define DUCK_HITBOX_X   mpos.x > spos.x - 20 && mpos.x < spos.x + 86
#define DUCK_HITBOX_Y   mpos.y > spos.y - 20 && mpos.y < spos.y + 86
#define CHILD_HITBOX_X  mpos.x > spos.x - 20 && mpos.x < spos.x + 200
#define CHILD_HITBOX_Y  mpos.y > spos.y - 20 && mpos.y < spos.y + 200
#define MOLE_HITBOX_X   mpos.x > spos.x - 10 && mpos.x < spos.x + 36
#define MOLE_HITBOX_Y   mpos.y > spos.y - 10 && mpos.y < spos.y + 36
#define PAUSE_BUTTON_X  ipos.x > 717 && ipos.x < 813
#define PAUSE_BUTTON_Y  ipos.y < 64 && ipos.y > 0
#define RETURN_BUTTON_X ipos.x > 342 && ipos.x < 471
#define RETURN_BUTTON_Y ipos.y > 176 && ipos.y < 241
#define BACK_TO_MENU_X  ipos.x > 342 && ipos.x < 471
#define BACK_TO_MENU_Y  ipos.y > 272 && ipos.y < 337
#define QUIT_BUTTON_X   ipos.x > 342 && ipos.x < 471
#define QUIT_BUTTON_Y   ipos.y > 369 && ipos.y < 433
#define DUCK            main->ducks->duck
#define CHILD           main->child->child
#define MOLE            main->sprites->mole
#define SHOTED          main->shoteds->shoted
#define INTS            main->ints
#define DUCK_SPAWN      1 + rand() % 3
#define CHILD_SPAWN     4 + rand() % 16
#define MOLE_SPAWN      10 + rand() % 50

sfSprite *create_background(void);
sfSprite *create_pause_button(void);
sfSprite *create_menu(void);
sfSound *create_sound(char *soundfile);
sfSprite *create_sight(void);
int sight_sprite(sfRenderWindow *window, sfSprite *sight);
void move_rect(sfIntRect *rect, int offset, int max_value);

typedef struct duck_structure
{
    sfSprite *sprite;
    sfTexture *texture_left;
    sfTexture *texture_right;
    sfClock *frame;
    sfIntRect frame_cam;
    sfVector2f vector;
    int color;
} duck_t;

typedef struct child_structure
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect frame_cam;
    sfVector2f vector;
} child_t;

typedef struct shoted_structure
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vector;
    sfClock *time;
} shoted_t;

typedef struct linked_duck_list
{
    duck_t *duck;
    struct linked_duck_list *next;
} duck_l;

typedef struct linked_child_list
{
    child_t *child;
    struct linked_child_list *next;
} child_l;

typedef struct linked_shoted_list
{
    shoted_t *shoted;
    struct linked_shoted_list *next;
} shoted_l;

typedef struct mole_sprite_structure
{
    sfSprite *sprite;
    sfClock *frame;
    sfIntRect rect;
    sfVector2f pos;
    int state;
}mole_t;

typedef struct all_sprite
{
    sfSprite *background;
    sfSprite *pause;
    sfSprite *sight;
    sfSprite *bush_right;
    sfSprite *bush_left;
    sfSprite *duck_count;
    mole_t *mole;
} sprites_t;

typedef struct all_sound
{
    sfSound *coin;
    sfSound *shotgun;
    sfClock *reload;
} sound_t;

typedef struct all_texts
{
    sfText *score;
    sfText *combo;
    sfText *kills;
} txt_t;

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

typedef struct dificulty_struct_vars
{
    int duck_speed;
    int child_speed;
    int step;
} difficulty_t;

typedef struct struc_structures
{
    duck_l *ducks;
    child_l *child;
    shoted_l *shoteds;
    sprites_t *sprites;
    txt_t *texts;
    sound_t *sounds;
    ints_t *ints;
    difficulty_t *difficulty;
    int stop_game;
} main_t;

int move_sprite(duck_t *ducks, int speed);
void add_duck(duck_l **head, duck_t *duck);
duck_t *create_duck(int x, int y);
int move_a_duck(duck_t *duck, difficulty_t *diff);
int move_ducks(main_t *main, sfRenderWindow *window);
int delete_duck(duck_l **start, int branch);
int is_having_to_close(sfRenderWindow *window, int bool);
int is_having_to_pause(sfRenderWindow *window, main_t *main);
int stop(main_t *main);
sprites_t *init_sprites(void);
sound_t *init_sound(void);
sfText *create_score(void);
ints_t *init_ints(void);
sfText *create_combo(void);
sfText *create_kill(void);
main_t *init_main_struct(main_t *main);
void add_child(child_l **head, child_t *child);
int delete_child(child_l **start, int branch);
child_t *create_child(int bool, int x, int y);
int move_child(child_l *childs, int child_nbr, sfRenderWindow *window);
shoted_t *create_shoted(sfSprite *sprite, sfIntRect shoted_all, char *filepath);
void add_shoted(shoted_l **head, shoted_t *shoted);
int delete_shoted(shoted_l **start, int branch);
int move_shoted(shoted_l *shoteds, int shoted_nbr, sfRenderWindow *window);
int child_spawning(main_t *main);
int duck_spawning(main_t *main);
mole_t *create_mole(void);
int anim_mole(main_t *main);
int mole_spawn(main_t *main);
int free_duck(duck_l *ducks);
int free_child(child_l *childs);
int free_death(shoted_l *shoteds);
int dificulty_update(main_t *main);
sfSprite *create_bush(int x, int y);
sfSprite *create_duck_count(void);
int while_focus(main_t *main, sfRenderWindow *window);
int kill_mole(sfRenderWindow *window, main_t *main);
int kill_child(sfRenderWindow *window, main_t *main);
int kill_duck(sfRenderWindow *window, main_t *main);
int game_over(sfRenderWindow *window, main_t *main);
int display_all(sfRenderWindow *window, main_t *main);

#endif