/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** react_button_fight
*/

#include "rpg.h"

static int check_pressed(game_t *game, int value)
{
    int damage = ((game->hud->stat[4] * 2) - game->fight->stats[1]);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->time = sfClock_getElapsedTime(game->clock);
        if (sfTime_asSeconds(game->time) >= sfTime_asSeconds(sfSeconds(1))) {
                sfClock_restart(game->clock);
                game->time = sfTime_Zero;
                if (value == 1) {
                    game->fight->stats[0] -= damage;
                    sfSound_play(game->fight->hurt);
                }
                if (value == 2)
                    game->fight->comp = 2;
                return (TRUE);
            }
    }
    return (FALSE);
}

int react_button_fight(fight_t *fight, game_t *game)
{
    sfColor outline = sfColor_fromRGBA(128, 0, 0, 200);
    sfColor selected = sfColor_fromRGBA(255, 255, 255, 200);

    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    sfRectangleShape_setOutlineColor(fight->but1, outline);
    sfRectangleShape_setOutlineColor(fight->but2, outline);
    if (game->mouse.x >= 955 && game->mouse.x <= 1165)
        if (game->mouse.y >= 245 && game->mouse.y <= 355) {
            sfRectangleShape_setOutlineColor(fight->but1, selected);
            if (check_pressed(game, 1))
                return (TRUE);
        }
    if (game->mouse.x >= 955 && game->mouse.x <= 1165)
        if (game->mouse.y >= 445 && game->mouse.y <= 555) {
            sfRectangleShape_setOutlineColor(fight->but2, selected);
            if (check_pressed(game, 2))
                return (TRUE);
        }
    return (FALSE);
}
