/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** system fonctions
*/

#include "duck_hunt.h"

int menu(sfRenderWindow *window, int first_open);

int scorboard(sfRenderWindow *window, ints_t *ints, int write);

int dificulty_update(main_t *main)
{
    if (INTS->score > main->difficulty->step * 500) {
        main->difficulty->duck_speed += 1;
        INTS->mole_next_spawn = MOLE_SPAWN;
        main->difficulty->step++;
    }
}

int is_having_to_close(sfRenderWindow *window, int bool)
{
    sfEvent event;
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (bool == 1 && sfMouse_isButtonPressed(sfMouseLeft) && QUIT_BUTTON_X
                        && QUIT_BUTTON_Y) {
            sfRenderWindow_close(window);
            return (1);
        }
    }
    return (0);
}

int pause(sfRenderWindow *window, main_t *main)
{
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_display(window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && RETURN_BUTTON_X
                    && RETURN_BUTTON_Y)
        return (0);
    if (is_having_to_close(window, 1))
        return (0);
    if (sfMouse_isButtonPressed(sfMouseLeft) && BACK_TO_MENU_X
                    && BACK_TO_MENU_Y) {
        if (menu(window, 0) == 2) {
            stop(main);
            init_main_struct(main);
        }
        return (0);
    }
    return (1);
}

int is_having_to_pause(sfRenderWindow *window, main_t *main)
{
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);
    sfSprite *menu;

    if (sfMouse_isButtonPressed(sfMouseLeft) && PAUSE_BUTTON_X
                    && PAUSE_BUTTON_Y) {
        menu = create_menu();
        sfRenderWindow_setMouseCursorVisible(window, 1);
        sfRenderWindow_drawSprite(window, menu, NULL);
        sfRenderWindow_display(window);
        while (pause(window, main)) {}
        sfRenderWindow_setMouseCursorVisible(window, 0);
        sfSprite_destroy(menu);
        my_wait(100000000);
    }
}

int game_over(sfRenderWindow *window, main_t *main)
{
    sfVector2f move = {-3, -2.9};

    if (INTS->kills <= 0) {
        for (int i = 0; i < 95; i++) {
            sfText_move(main->texts->score, move);
            display_all(window, main);
        }
        scorboard(window, INTS, 1);
        stop(main);
        menu(window, 0);
        init_main_struct(main);
    }
}