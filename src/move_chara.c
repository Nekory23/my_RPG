/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** animation of the movement of the character
*/

#include "rpg.h"

void move_up(game_t *game, play_t *play)
{
    play->rect.top = 1040;
    game->time = sfClock_getElapsedTime(game->clock);
    if (sfTime_asSeconds(game->time) >= sfTime_asSeconds(sfSeconds(0.05))) {
        sfClock_restart(game->clock);
        game->time = sfTime_Zero;
        change_map_up(play);
        if (check_colision_y(play, 1) == FALSE)
            play->pos.y -= 10;
        if (play->rect.left >= 3900)
            play->rect.left = 260;
        sfSprite_setPosition(play->player_s, play->pos);
        sfSprite_setTextureRect(play->player_s, play->rect);
        play->rect.left += 260;
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
    }
}

void move_down(game_t *game, play_t *play)
{
    play->rect.top = 0;
    game->time = sfClock_getElapsedTime(game->clock);
    if (sfTime_asSeconds(game->time) >= sfTime_asSeconds(sfSeconds(0.05))) {
        sfClock_restart(game->clock);
        game->time = sfTime_Zero;
        change_map_down(play);
        if (check_colision_y(play, 0) == FALSE)
            play->pos.y += 10;
        if (play->rect.left >= 3900)
            play->rect.left = 260;
        sfSprite_setPosition(play->player_s, play->pos);
        sfSprite_setTextureRect(play->player_s, play->rect);
        play->rect.left += 260;
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
    }
}

void move_right(game_t *game, play_t *play)
{
    play->rect.top = 520;
    game->time = sfClock_getElapsedTime(game->clock);
    if (sfTime_asSeconds(game->time) >= sfTime_asSeconds(sfSeconds(0.05))) {
        sfClock_restart(game->clock);
        game->time = sfTime_Zero;
        change_map_right(play);
        if (check_colision_x(play, 0) == FALSE)
            play->pos.x += 10;
        if (play->rect.left >= 3900)
            play->rect.left = 260;
        sfSprite_setPosition(play->player_s, play->pos);
        sfSprite_setTextureRect(play->player_s, play->rect);
        play->rect.left += 260;
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
    }
}

void move_left(game_t *game, play_t *play)
{
    play->rect.top = 520;
    game->time = sfClock_getElapsedTime(game->clock);
    if (sfTime_asSeconds(game->time) >= sfTime_asSeconds(sfSeconds(0.05))) {
        sfClock_restart(game->clock);
        game->time = sfTime_Zero;
        change_map_left(play);
        if (check_colision_x(play, 1) == FALSE)
            play->pos.x -= 10;
        if (play->rect.left >= 3900)
            play->rect.left = 260;
        sfSprite_setPosition(play->player_s, play->pos);
        sfSprite_setTextureRect(play->player_s, play->rect);
        play->rect.left += 260;
        sfRenderWindow_drawSprite(game->win, game->play->player_s, NULL);
    }
}
