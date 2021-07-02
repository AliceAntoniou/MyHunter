/*
** EPITECH PROJECT, 2020
** duck_hunt
** File description:
** game over fonctions
*/

#include "scoreboard.h"

int is_leaving(sfRenderWindow *window)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && BACK_TO_MENU_X
                    && BACK_TO_MENU_Y) {
        while (sfMouse_isButtonPressed(sfMouseLeft)) {}
        return (0);
    }
    return (1);
}

int display_all_2(sfRenderWindow *window, sprites_t *sprites)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, sprites->scoreboard, NULL);
    sfRenderWindow_drawSprite(window, sprites->game_over, NULL);
    sfRenderWindow_drawSprite(window, sprites->back_to_menu, NULL);
    sfRenderWindow_drawText(window, sprites->score, NULL);
    sfRenderWindow_display(window);
}

int scorboard(sfRenderWindow *window, ints_t *ints)
{
    sprites_t *sprites = game_over_sprites();
    sfVector2f score_pos = {425 - my_getlen(ints->score) * 15, 260};
    char *str = get_score();
    int open = 1;

    sfText_setString(sprites->scoreboard, str);
    sfText_setPosition(sprites->score, score_pos);
    sfText_setString(sprites->score, my_getstr(ints->score));
    while (sfRenderWindow_isOpen(window) && open == 1) {
        sfRenderWindow_setMouseCursorVisible(window, 1);
        is_having_to_close(window, 0);
        display_all_2(window, sprites);
        open = is_leaving(window);
    }
    write_scoreboard(str, my_getstr(ints->score));
    return 0;
}