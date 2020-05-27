/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** interact with the inventory
*/

#include "rpg.h"

static int check_inside(sfVector2f pos, int size, sfVector2i mouse)
{
    if (mouse.x >= (pos.x - 5) && mouse.x <= (pos.x + size))
        if (mouse.y >= (pos.y - 5) && mouse.y <= (pos.y + size))
            return (TRUE);
    return (FALSE);
}

static void drag_n_drop(game_t *game, int x, int y)
{
    sfVector2f pos;

    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    while (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->win);
        sfRenderWindow_drawSprite(game->win, game->inven->item_s, NULL);
    }
    for (int i = 0; i != 6; i++)
        for (int j = 0; j != 4; j++) {
            if (check_inside(game->inven->pos[i][j], 60, game->mouse)) {
                game->inven->slot[x][y] = 0;
                game->inven->slot[i][j] = 1;
                pos = game->inven->pos[i][j];
                sfSprite_setPosition(game->inven->item_s, pos);
                sfRenderWindow_drawSprite(game->win, game->inven->item_s, NULL);
                return;
            }
        }
    sfSprite_setPosition(game->inven->item_s, game->inven->pos[0][0]);
}

void interact_inv(inven_t *inven, game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->win, sfTrue);
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    for (int i = 0; i != 6; i++)
        for (int j = 0; j != 4; j++) {
            if (inven->slot[i][j] == 0)
                continue;
            if (check_inside(inven->pos[i][j], 60, game->mouse))
                drag_n_drop(game, i, j);
        }
    sfRenderWindow_setMouseCursorVisible(game->win, sfFalse);
}
