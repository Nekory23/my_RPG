/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** get dir
*/

#include "rpg.h"

static void dir_left_right(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_setScale(game->play->player_s, (sfVector2f){1, 1});
        move_right(game, game->play);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_setScale(game->play->player_s, (sfVector2f){-1, 1});
        move_left(game, game->play);
    }
    else {
        game->play->rect.left = 0;
        sfSprite_setTextureRect(game->play->player_s, game->play->rect);
    }
}

void get_dir(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->play->player_s);

    game->play->pos.x = pos.x;
    game->play->pos.y = pos.y;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move_down(game, game->play);
    else if (sfKeyboard_isKeyPressed(sfKeyUp))
        move_up(game, game->play);
    else
        dir_left_right(game);
}
