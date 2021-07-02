/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** menu
*/

#include "duck_menu.h"

int bouttons(sfRenderWindow *window, int first_open)
{
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && QUIT_BUTTON_X && QUIT_BUTTON_Y)
        sfRenderWindow_close(window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && NEW_GAME_X && NEW_GAME_Y) {
        sfRenderWindow_setMouseCursorVisible(window, 0);
        if (first_open)
            game(window);
        else
            return (2);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && CONTINUE_X && CONTINUE_Y) {
        sfRenderWindow_setMouseCursorVisible(window, 0);
        if (first_open)
            game(window);
        else
            return (1);
    }
    return (0);
}

int help_menu(sfRenderWindow *window, sfSprite *help)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && HELP_X && HELP_Y) {
        sfRenderWindow_drawSprite(window, help, NULL);
        sfRenderWindow_display(window);
        my_wait(100000000);
        while (sfMouse_isButtonPressed(sfMouseLeft) == 0) {}
    }
}

int destroy_all(sprites_t *sprites)
{
    sfSprite_destroy(sprites->background);
    sfSprite_destroy(sprites->buttons);
    sfSprite_destroy(sprites->help);
    sfSprite_destroy(sprites->help_button);
    sfText_destroy(sprites->title);
    free(sprites);
}

int menu(sfRenderWindow *window, int first_open)
{
    sprites_t *sprites = menu_sprites();
    int var = 0;

    while (sfRenderWindow_isOpen(window) && var == 0) {
        is_having_to_close(window, 0);
        sfRenderWindow_drawSprite(window, sprites->background, NULL);
        sfRenderWindow_drawSprite(window, sprites->buttons, NULL);
        sfRenderWindow_drawText(window, sprites->title, NULL);
        sfRenderWindow_drawSprite(window, sprites->help_button, NULL);
        sfRenderWindow_display(window);
        help_menu(window, sprites->help);
        var = bouttons(window, first_open);
    }
    destroy_all(sprites);
    return (var);
}

int main(int ac, char **av)
{
    sfRenderWindow *window = create_window();

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\nProjet: my_hunter\n\n");
        my_putstr("Goal:\nGet the maximum score while avoiding\n");
        my_putstr("children and killing as few ducks as possible.\n");
        my_putstr("For more information, see the help page in the menu.\n\n");
        return (0);
    }
    menu(window, 1);
    sfRenderWindow_destroy(window);
    return (0);
}