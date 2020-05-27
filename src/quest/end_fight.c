/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display the end fight screen
*/

#include "rpg.h"

static int react_button_end(fight_t *fight, game_t *game)
{
    sfColor outline = sfColor_fromRGB(128, 0, 0);

    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    sfRectangleShape_setOutlineColor(fight->but1, outline);
    if (game->mouse.x >= 1015 && game->mouse.x <= 1200)
        if (game->mouse.y >= 445 && game->mouse.y <= 550) {
            sfRectangleShape_setOutlineColor(fight->but1, sfWhite);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (1);
        }
    return (FALSE);
}

static void draw_text(sfText *text, sfRenderWindow *win)
{
    sfColor color = sfColor_fromRGB(128, 0, 0);

    sfText_setColor(text, color);
    sfText_setCharacterSize(text, 70);
    sfText_setString(text, "You defeated the Sram !");
    sfText_setPosition(text, (sfVector2f) {930, 250});
    sfRenderWindow_drawText(win, text, NULL);
    sfText_setCharacterSize(text, 60);
    sfText_setString(text, "You gain 7xps !");
    sfText_setPosition(text, (sfVector2f) {980, 350});
    sfRenderWindow_drawText(win, text, NULL);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, "Yaaay !");
    sfText_setPosition(text, (sfVector2f) {1050, 470});
    sfRenderWindow_drawText(win, text, NULL);
}

static void place_player(game_t *game)
{
    sfMusic_pause(game->fight->battle);
    sfMusic_play(game->play->village);
    game->play->rect.top = 0;
    game->play->change_m = 2;
    game->quest->kill = 1;
    game->quest->status = 2;
    game->fight_i = 1;
    game->hud->stat[2] += 7;
    game->play->end_fight = 1;
}

static void win_fight(game_t *game)
{
    int pressed = 0;
    sfVector2f pos = {1020, 450};

    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        draw_player(game);
        display_hud(game->hud, game->win);
        sfRenderWindow_drawRectangleShape(game->win, game->fight->bkgd, NULL);
        sfRectangleShape_setPosition(game->fight->but1, pos);
        sfRenderWindow_drawRectangleShape(game->win, game->fight->but1, NULL);
        draw_text(game->fight->text, game->win);
        pressed = react_button_end(game->fight, game);
        if (pressed == 1)
            break;
        display_cursor(game);
        sfRenderWindow_display(game->win);
    }
    place_player(game);
}

void display_end_fight(game_t *game, int win)
{
    game->status = 1;
    switch (win) {
    case 1 :
        win_fight(game);
        break;
    case 2 :
        game_over(game);
        break;
    }
}
