/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display the game
*/

#include "rpg.h"

void get_event(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->ret = PAUSE;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        game->ret = MENU;
    get_dir(game);
}

void display_pause(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        react_button_pause(game);
        if (game->ret == GAME)
            break;
        if (game->ret == END || game->ret == MAIN) {
            sfMusic_pause(game->play->village);
            sfRenderWindow_close(game->win);
        }
        sfRenderWindow_clear(game->win, sfBlack);
        draw_player(game);
        draw_pause(game);
        sfRenderWindow_display(game->win);
    }
}

static void display_what(game_t *game)
{
    switch (game->ret) {
    case 3 :
        display_pause(game);
        break;
    case 4 :
        display_inventory(game);
        break;
    }
}

static void check_fight_end(game_t *game)
{
    if (game->fight_i == 1) {
        game->play->pos.x = 700;
        game->play->pos.y = 100;
        game->fight_i = 0;
        sfSprite_setPosition(game->play->player_s, game->play->pos);
    }
    if (game->over == 1) {
        game->play->pos.x = 1270;
        game->play->pos.y = 800;
        game->over = 0;
        sfSprite_setPosition(game->play->player_s, game->play->pos);
    }
}

void display_game(game_t *game)
{
    if (game->chara == 0)
        choose_player(game);
    sfMusic_pause(game->menu->music);
    sfMusic_play(game->play->village);
    sfMusic_setLoop(game->play->village, sfTrue);
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        get_event(game);
        sfRenderWindow_clear(game->win, sfBlack);
        if (game->ret != GAME)
            display_what(game);
        if (game->play->change_m == 0)
            quest_handling(game);
        if (game->play->change_m == 3 && game->status == 0)
            battle_start(game);
        check_fight_end(game);
        draw_player(game);
        display_hud(game->hud, game->win);
        display_cursor(game);
        sfRenderWindow_display(game->win);
    }
}
