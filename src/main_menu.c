/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display the main menu
*/

#include "rpg.h"

void event_close(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win, &game->event))
        if (game->event.type == sfEvtClosed) {
            game->ret = END;
            sfRenderWindow_close(game->win);
        }
}

static void display_how_to_play(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        sfRenderWindow_clear(game->win, sfBlack);
        react_button_htp(game);
        if (game->ret == MAIN)
            break;
        draw_how_to_play(game);
        sfRenderWindow_display(game->win);
    }
}

void start_game(game_t *game)
{
    fill_struct(game);
    sfRenderWindow_setFramerateLimit(game->win, 60);
    sfMusic_play(game->menu->music);
    sfMusic_setLoop(game->menu->music, sfTrue);
    sfRenderWindow_setMouseCursorVisible(game->win, sfFalse);
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        if (game->ret == MAIN) {
            react_button_main(game);
            draw_main_menu(game);
        }
        else if (game->ret == END || game->ret == HTP) {
            if (game->ret == END)
                break;
            display_how_to_play(game);
        }
        else
            display_game(game);
        sfRenderWindow_display(game->win);
    }
    my_destroy(game);
}
