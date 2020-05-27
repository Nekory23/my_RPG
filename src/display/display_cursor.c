/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** display of cursor
*/

#include "rpg.h"

void display_cursor(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->win);

    game->cursor->pos.x = pos.x;
    game->cursor->pos.y = pos.y;
    sfRectangleShape_setPosition(game->cursor->cursor_m, game->cursor->pos);
    sfRenderWindow_drawRectangleShape(game->win, game->cursor->cursor_m, NULL);
}
