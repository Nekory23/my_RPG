/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** makes the buttons change color and clickable
*/

#include "rpg.h"

static void reset_colors(game_t *game)
{
    sfRectangleShape_setOutlineColor(game->menu->but, game->menu->box_c);
    sfRectangleShape_setOutlineColor(game->menu->but2, game->menu->box_c);
    sfRectangleShape_setOutlineColor(game->menu->but3, game->menu->box_c);
    sfText_setColor(game->menu->play, game->menu->text_c);
    sfText_setColor(game->menu->quit, game->menu->text_c);
    sfText_setColor(game->menu->htp, game->menu->text_c);
}

static void change_colors(game_t *game, int but)
{
    switch (but) {
    case 1 :
        sfRectangleShape_setOutlineColor(game->menu->but, game->menu->text_c);
        sfText_setColor(game->menu->play, game->menu->box_c);
        break;
    case 2 :
        sfRectangleShape_setOutlineColor(game->menu->but2, game->menu->text_c);
        sfText_setColor(game->menu->quit, game->menu->box_c);
        break;
    case 3 :
        sfRectangleShape_setOutlineColor(game->menu->but3, game->menu->text_c);
        sfText_setColor(game->menu->htp, game->menu->box_c);
        break;
    }
}

void react_button_main(game_t *game)
{
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    reset_colors(game);
    if (game->mouse.x >= (game->menu->pos.x - 5) && game->mouse.x <= 1255)
        if (game->mouse.y >= (game->menu->pos.y - 5) && game->mouse.y <= 360) {
            change_colors(game, 1);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                game->ret = GAME;
        }
    if (game->mouse.x >= (game->menu->pos2.x - 5) && game->mouse.x <= 1655)
        if (game->mouse.y >= (game->menu->pos2.y - 5) && game->mouse.y <= 360) {
            change_colors(game, 2);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                game->ret = END;
        }
    if (game->mouse.x >= (game->menu->pos3.x - 5) && game->mouse.x <= 1590)
        if (game->mouse.y >= (game->menu->pos3.y - 5) && game->mouse.y <= 510) {
            change_colors(game, 3);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                game->ret = HTP;
        }
}
