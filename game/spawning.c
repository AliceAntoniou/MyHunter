/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** spawning fonctions
*/

#include "duck_hunt.h"

int child_spawning(main_t *main)
{
    int rdm = rand() % 2;

    if (sfTime_asSeconds(sfClock_getElapsedTime(INTS->child_time_passed))
                    > INTS->child_next_spawn) {
        if (rdm == 0) {
            add_child(&main->child, create_child(1, 850, rand() % 310));
            INTS->child_next_spawn = CHILD_SPAWN;
            sfClock_restart(INTS->child_time_passed);
            INTS->child_nbr++;
        }
        if (rdm == 1) {
            add_child(&main->child, create_child(0, -50, rand() % 310));
            INTS->child_next_spawn = CHILD_SPAWN;
            sfClock_restart(INTS->child_time_passed);
            INTS->child_nbr++;
        }
    }
    return (0);
}

int duck_spawning(main_t *main)
{
    int rdm = rand() % 2;

    if (sfTime_asSeconds(sfClock_getElapsedTime(INTS->duck_time_passed))
                    > INTS->duck_next_spawn) {
        if (rdm == 0) {
            add_duck(&main->ducks, create_duck(173, 430));
            sfSound_play(main->sounds->coin);
            INTS->duck_next_spawn = DUCK_SPAWN;
            sfClock_restart(INTS->duck_time_passed);
            INTS->duck_nbr++;
        }
        if (rdm == 1) {
            add_duck(&main->ducks, create_duck(570, 430));
            sfSound_play(main->sounds->coin);
            INTS->duck_next_spawn = DUCK_SPAWN;
            sfClock_restart(INTS->duck_time_passed);
            INTS->duck_nbr++;
        }
    }
}

int mole_spawn(main_t *main)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(INTS->mole_time_passed))
                    > INTS->mole_next_spawn) {
        INTS->mole_next_spawn = 1000;
        MOLE->pos.x = rand() % 767 + 10;
        MOLE->state = 0;
        sfClock_restart(INTS->mole_time_passed);
    }
    return (0);
}