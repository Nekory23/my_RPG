/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** draw map
*/

#include "rpg.h"

static void draw_map_bis(game_t *game)
{
    if (game->play->change_m == 0) {
        sfRenderWindow_drawSprite(game->win, game->play->map_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->map_sb, NULL);
        if (game->quest->status != 3)
            draw_quest_bubble(game->quest->status, game);
        sfRenderWindow_drawSprite(game->win, game->quest->pnj_s, NULL);
    }
    else if (game->play->change_m == 3) {
        sfRenderWindow_drawSprite(game->win, game->play->map_fight_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->fight->enemy_s, NULL);
        sfSprite_setTextureRect(game->play->player_s, game->fight->rect);
        sfSprite_setScale(game->play->player_s, (sfVector2f) {-1, 1});
        sfSprite_setPosition(game->play->player_s, game->play->pos);
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->map_fight_sb, NULL);
    }
}

void draw_map(game_t *game)
{
    if (game->play->change_m == 1) {
        sfRenderWindow_drawSprite(game->win, game->play->map1_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->map1_sb, NULL);
    }
    else if (game->play->change_m == 2) {
        sfRenderWindow_drawSprite(game->win, game->play->map2_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->play->map2_sb, NULL);
    }
    else
        draw_map_bis(game);
}
