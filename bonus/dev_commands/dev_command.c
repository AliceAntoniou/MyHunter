/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** developer commands
*/

#include "../../game/duck_hunt.h"

int game(void);

int dev_command(main_t *main, sfRenderWindow *window)
{
    sfVector2f pos = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfSprite_setPosition(MOLE->sprite, pos);
        MOLE->state = 0;
    }
    return (0);
}