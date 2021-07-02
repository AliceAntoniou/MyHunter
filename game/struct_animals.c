/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** animals creation
*/

#include "duck_hunt.h"

duck_t *create_duck_2(duck_t *duck);

child_t *create_child_2(int bool, child_t *child);

mole_t *create_mole_2(mole_t *mole);

duck_t *create_duck(int x, int y)
{
    duck_t *duck = malloc(sizeof(duck_t));
    sfVector2f pos = {x, y};
    sfVector2f scale = {0.6, 0.6};

    duck->frame_cam.top = 0;
    duck->frame_cam.left = 0;
    duck->frame_cam.height = 110;
    duck->frame_cam.width = 110;
    duck->vector.x = 0;
    duck->vector.y = 0;
    duck->sprite = sfSprite_create();
    sfSprite_setPosition(duck->sprite, pos);
    sfSprite_setScale(duck->sprite, scale);
    return (create_duck_2(duck));
}

child_t *create_child(int bool, int x, int y)
{
    child_t *child = malloc(sizeof(child_t));
    sfVector2f pos = {x, y};
    sfVector2f scale = {4, 4};

    child->vector.y = 0;
    child->sprite = sfSprite_create();
    sfSprite_setPosition(child->sprite, pos);
    sfSprite_setScale(child->sprite, scale);
    return (create_child_2(bool, child));
}

shoted_t *create_shoted(sfSprite *sprite, sfIntRect shoted_all, char *filepath)
{
    shoted_t *shoted = malloc(sizeof(shoted_t));
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f scale = sfSprite_getScale(sprite);

    shoted->vector.y = 0;
    shoted->vector.x = 0;
    shoted->sprite = sfSprite_create();
    shoted->texture = sfTexture_createFromFile(filepath, &shoted_all);
    shoted->time = sfClock_create();
    sfSprite_setColor(shoted->sprite, sfSprite_getColor(sprite));
    sfSprite_setTexture(shoted->sprite, shoted->texture, 1);
    sfSprite_setPosition(shoted->sprite, pos);
    sfSprite_setScale(shoted->sprite, scale);
    return (shoted);
}

mole_t *create_mole(void)
{
    mole_t *mole = malloc(sizeof(mole_t));
    sfIntRect cam_mole = {0, 0, 384, 192};
    sfVector2f scale = {0.4, 0.4};
    sfTexture *mole_t = sfTexture_createFromFile(
                    "textures/Taupe.png", &cam_mole);

    mole->sprite = sfSprite_create();
    mole->frame = sfClock_create();
    mole->state = -2;
    mole->pos.x = -200;
    mole->pos.y = 495;
    sfSprite_setPosition(mole->sprite, mole->pos);
    sfSprite_setTexture(mole->sprite, mole_t, 1);
    sfSprite_setScale(mole->sprite, scale);
    return (create_mole_2(mole));
}