/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main
*/

#include "duck_hunt.h"

int combo_display(sfRenderWindow *window, ints_t *ints, sfText *combo_txt)
{
    char str[4] = "x";
    char dest[4];

    if (ints->combo < 2)
        return (0);
    if (ints->combo > 1)
        sfText_setColor(combo_txt, sfBlack);
    if (ints->combo > 4)
        sfText_setColor(combo_txt, sfBlue);
    if (ints->combo > 9) {
        sfText_setColor(combo_txt, sfRed);
        sfText_setString(combo_txt, my_strcat(my_strcpy(dest, str), "10"));
        sfRenderWindow_drawText(window, combo_txt, NULL);
        return (0);
    }
    sfText_setString(combo_txt, my_strcat(
                my_strcpy(dest, str), my_getstr(ints->combo)));
    sfRenderWindow_drawText(window, combo_txt, NULL);
    return (0);
}

int set_txt_padding(main_t *main)
{
    sfVector2f score_pos = {720 - my_getlen(INTS->score) * 15, 540};
    sfVector2f kills_pos = {100 - my_getlen(INTS->kills) * 15, 540};

    sfText_setPosition(main->texts->score, score_pos);
    sfText_setPosition(main->texts->kills, kills_pos);
}

int set_all_to_date(sfRenderWindow *window, main_t *main)
{
    sfVector2f cam_shake = {0, 0};

    duck_spawning(main);
    child_spawning(main);
    mole_spawn(main);
    sfText_setString(main->texts->score, my_getstr(INTS->score));
    sfText_setString(main->texts->kills, my_getstr(INTS->kills));
    set_txt_padding(main);
    anim_mole(main);
    sfSprite_setTextureRect(MOLE->sprite, MOLE->rect);
    sfSprite_setPosition(main->sprites->background, cam_shake);
}

int display_all(sfRenderWindow *window, main_t *main)
{
    sfRenderWindow_drawSprite(window, main->sprites->background, NULL);
    move_ducks(main, window);
    sfRenderWindow_drawSprite(window, main->sprites->bush_left, NULL);
    sfRenderWindow_drawSprite(window, main->sprites->bush_right, NULL);
    move_child(main->child, INTS->child_nbr, window);
    move_shoted(main->shoteds, INTS->shoted_nbr, window);
    sfRenderWindow_drawSprite(window, main->sprites->pause, NULL);
    sfRenderWindow_drawText(window, main->texts->score, NULL);
    combo_display(window, INTS, main->texts->combo);
    sfRenderWindow_drawSprite(window, main->sprites->duck_count, NULL);
    sfRenderWindow_drawText(window, main->texts->kills, NULL);
    sfRenderWindow_drawSprite(window, MOLE->sprite, NULL);
    sight_sprite(window, main->sprites->sight);
    sfRenderWindow_display(window);
}

int game(sfRenderWindow *window)
{
    main_t main;

    init_main_struct(&main);
    sfRenderWindow_setMouseCursorVisible(window, 0);
    while (sfRenderWindow_isOpen(window)) {
        if (sfRenderWindow_hasFocus(window)) {
            while_focus(&main, window);
        }
        if (main.ints->score < 0)
            main.ints->score = 0;
        display_all(window, &main);
        set_all_to_date(window, &main);
        dificulty_update(&main);
        is_having_to_close(window, 0);
        is_having_to_pause(window, &main);
        game_over(window, &main);
    }
    stop(&main);
    return (0);
}