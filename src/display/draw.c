/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** draw what's in the window
*/

#include "rpg.h"

void draw_how_to_play(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->menu->bgd_s, NULL);
    sfRenderWindow_drawSprite(game->win, game->how->scroll_s, NULL);
    sfRenderWindow_drawText(game->win, game->how->text, NULL);
    sfRenderWindow_drawText(game->win, game->how->ret, NULL);
    sfText_setString(game->how->htp, STR_HTP);
    sfText_setPosition(game->how->htp, (sfVector2f) {680, 300});
    sfRenderWindow_drawText(game->win, game->how->htp, NULL);
    sfText_setString(game->how->htp, STR_HTP2);
    sfText_setPosition(game->how->htp, (sfVector2f) {680, 420});
    sfRenderWindow_drawText(game->win, game->how->htp, NULL);
    sfText_setString(game->how->htp, STR_HTP3);
    sfText_setPosition(game->how->htp, (sfVector2f) {680, 480});
    sfRenderWindow_drawText(game->win, game->how->htp, NULL);
    sfText_setString(game->how->htp, STR_HTP4);
    sfText_setPosition(game->how->htp, (sfVector2f) {680, 540});
    sfRenderWindow_drawText(game->win, game->how->htp, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->how->but, NULL);
    display_cursor(game);
}

void draw_main_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->menu->bgd_s, NULL);
    sfRenderWindow_drawText(game->win, game->menu->text, NULL);
    sfRenderWindow_drawText(game->win, game->menu->play, NULL);
    sfRenderWindow_drawText(game->win, game->menu->quit, NULL);
    sfRenderWindow_drawText(game->win, game->menu->htp, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->menu->but, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->menu->but2, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->menu->but3, NULL);
    display_cursor(game);
}

void draw_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->how->scroll_s, NULL);
    sfRenderWindow_drawText(game->win, game->pause->pause_t, NULL);
    sfRenderWindow_drawText(game->win, game->pause->quit, NULL);
    sfRenderWindow_drawText(game->win, game->pause->resume, NULL);
    sfRenderWindow_drawText(game->win, game->pause->main, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->pause->but, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->pause->but2, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->pause->but3, NULL);
    display_cursor(game);
}

void draw_choose_png(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->menu->bgd_s, NULL);
    sfRenderWindow_drawSprite(game->win, game->chac->but_s, NULL);
    sfRenderWindow_drawSprite(game->win, game->chac->type_s, NULL);
    sfRenderWindow_drawSprite(game->win, game->chac->type_s1, NULL);
    sfRenderWindow_drawSprite(game->win, game->chac->type_s2, NULL);
    sfRenderWindow_drawText(game->win, game->chac->choose, NULL);
    sfText_setString(game->chac->caract, "Cra, More life");
    sfText_setPosition(game->chac->caract, (sfVector2f) {200, 850});
    sfRenderWindow_drawText(game->win, game->chac->caract, NULL);
    sfText_setString(game->chac->caract, "Iop, More attack");
    sfText_setPosition(game->chac->caract, (sfVector2f) {820, 850});
    sfRenderWindow_drawText(game->win, game->chac->caract, NULL);
    sfText_setString(game->chac->caract, "Sram, More defense");
    sfText_setPosition(game->chac->caract, (sfVector2f) {1450, 850});
    sfRenderWindow_drawText(game->win, game->chac->caract, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->chac->choice, NULL);
    display_cursor(game);
}

void draw_player(game_t *game)
{
    draw_map(game);
    display_cursor(game);
}
