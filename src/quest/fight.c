/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fight scene
*/

#include "rpg.h"

static void draw_option_menu(fight_t *fight, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, fight->bkgd, NULL);
    sfRenderWindow_drawRectangleShape(win, fight->but1, NULL);
    sfRenderWindow_drawRectangleShape(win, fight->but2, NULL);
    sfText_setCharacterSize(fight->text, 60);
    sfText_setString(fight->text, "Attack");
    sfText_setPosition(fight->text, (sfVector2f) {990, 270});
    sfRenderWindow_drawText(win, fight->text, NULL);
    sfText_setString(fight->text, "Block");
    sfText_setPosition(fight->text, (sfVector2f) {990, 470});
    sfRenderWindow_drawText(win, fight->text, NULL);
    sfText_setCharacterSize(fight->text, 40);
    sfText_setString(fight->text, "Reduces damages\ntaken");
    sfText_setPosition(fight->text, (sfVector2f) {1190, 460});
    sfRenderWindow_drawText(win, fight->text, NULL);
    sfText_setString(fight->text, "Deals damages\ndepending on\n your attack");
    sfText_setPosition(fight->text, (sfVector2f) {1190, 240});
    sfRenderWindow_drawText(win, fight->text, NULL);

}

static int my_turn(game_t *game, int turn)
{
    game->fight->comp = 0;
    if (react_button_fight(game->fight, game))
        turn++;
    return (turn);
}

static int enemy_turn(game_t *game, int turn)
{
    int damage = ((game->fight->stats[2] * 2) - game->hud->stat[3]);

    if (game->fight->comp == 2)
        game->hud->stat[0] -= damage / 2;
    else
        game->hud->stat[0] -= damage;
    turn++;
    return (turn);
}

static int check_win(game_t *game)
{
    if (game->fight->stats[0] <= 0) {
        sfSound_play(game->fight->death);
        return (1);
    }
    if (game->hud->stat[0] <= 0)
        return (2);
    return (FALSE);
}

void battle_start(game_t *game)
{
    static int turn = 1;
    int win = 0;

    sfMusic_pause(game->play->village);
    sfMusic_play(game->fight->battle);
    sfMusic_setLoop(game->fight->battle, sfTrue);
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        if ((win = check_win(game)) != FALSE)
            break;
        else if (turn % 2 == 1)
            turn = my_turn(game, turn);
        else
            turn = enemy_turn(game, turn);
        draw_player(game);
        draw_option_menu(game->fight, game->win);
        display_hud(game->hud, game->win);
        display_cursor(game);
        sfRenderWindow_display(game->win);
    }
    display_end_fight(game, win);
}
