/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** reactions for the button in the how to play menu
*/

#include "rpg.h"

static void reset_colors(game_t *game)
{
    sfRectangleShape_setOutlineColor(game->how->but, game->menu->box_c);
    sfText_setColor(game->how->ret, game->menu->text_c);
}

static void change_colors(game_t *game)
{
    sfRectangleShape_setOutlineColor(game->how->but, game->menu->text_c);
    sfText_setColor(game->how->ret, game->menu->box_c);
}

void react_button_htp(game_t *game)
{
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    reset_colors(game);
    if (game->mouse.x >= (game->how->pos.x - 5) && game->mouse.x <= 1030)
        if (game->mouse.y >= (game->how->pos.y - 5) && game->mouse.y <= 800) {
            change_colors(game);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                game->ret = MAIN;
        }
}
