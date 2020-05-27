/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** game_over screen
*/

#include "rpg.h"

static void draw_text(fight_t *fight, sfRenderWindow *win)
{
    sfText_setCharacterSize(fight->text, 400);
    sfText_setString(fight->text, "Game Over :(");
    sfText_setPosition(fight->text, (sfVector2f) {250, 270});
    sfRenderWindow_drawText(win, fight->text, NULL);
    sfText_setCharacterSize(fight->text, 100);
    sfText_setString(fight->text, "Try again ?");
    sfText_setPosition(fight->text, (sfVector2f) {550, 770});
    sfRenderWindow_drawText(win, fight->text, NULL);
    sfText_setString(fight->text, "Quit game");
    sfText_setPosition(fight->text, (sfVector2f) {1050, 770});
    sfRenderWindow_drawText(win, fight->text, NULL);
}

static void draw_buttons(fight_t *fight, sfRenderWindow *win)
{
    sfRectangleShape_setFillColor(fight->but1, sfTransparent);
    sfRectangleShape_setSize(fight->but1, (sfVector2f) {400, 150});
    sfRectangleShape_setPosition(fight->but1, (sfVector2f) {520, 760});
    sfRenderWindow_drawRectangleShape(win, fight->but1, NULL);
    sfRectangleShape_setFillColor(fight->but2, sfTransparent);
    sfRectangleShape_setSize(fight->but2, (sfVector2f) {400, 150});
    sfRectangleShape_setPosition(fight->but2, (sfVector2f) {1000, 760});
    sfRenderWindow_drawRectangleShape(win, fight->but2, NULL);
}

static int react_button_game_over(fight_t *fight, game_t *game)
{
    sfColor outline = sfColor_fromRGB(128, 0, 0);
    sfColor selected = sfColor_fromRGB(255, 255, 255);

    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    sfRectangleShape_setOutlineColor(fight->but1, outline);
    sfRectangleShape_setOutlineColor(fight->but2, outline);
    if (game->mouse.x >= 515 && game->mouse.x <= 925)
        if (game->mouse.y >= 755 && game->mouse.y <= 905) {
            sfRectangleShape_setOutlineColor(fight->but1, selected);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (1);
        }
    if (game->mouse.x >= 995 && game->mouse.x <= 1395)
        if (game->mouse.y >= 755 && game->mouse.y <= 905) {
            sfRectangleShape_setOutlineColor(fight->but2, selected);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (2);
        }
    return (0);
}

void game_over(game_t *game)
{
    int pressed = 0;

    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        sfRenderWindow_clear(game->win, sfBlack);
        draw_text(game->fight, game->win);
        draw_buttons(game->fight, game->win);
        pressed = react_button_game_over(game->fight, game);
        if (pressed != 0) {
            if (pressed == 1)
                game->ret = MAIN;
            sfRenderWindow_close(game->win);
        }
        display_cursor(game);
        sfRenderWindow_display(game->win);
    }
    game->over = 1;
}
