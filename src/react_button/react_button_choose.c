/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** reaction of the buttons
*/

#include "rpg.h"

static void calc_nbr(game_t *game, int nbr)
{
    if (game->chac->rect_s.top == 500)
        nbr += 3;
    game->chara = nbr;
}

static void draw_square(game_t *game, int nbr)
{
    switch (nbr) {
    case 1 :
        game->chac->pos_c.x = 180;
        break;
    case 2 :
        game->chac->pos_c.x = 820;
        break;
    case 3 :
        game->chac->pos_c.x = 1470;
        break;
    }
    game->chac->pos_c.y = 430;
    sfRectangleShape_setPosition(game->chac->choice, game->chac->pos_c);
    sfRectangleShape_setOutlineColor(game->chac->choice, game->chac->color);
}

void react_button_choose_c(game_t *game)
{
    sfRectangleShape_setOutlineColor(game->chac->choice, sfTransparent);
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    if (game->mouse.x >= 180 && game->mouse.x <= 420)
        if (game->mouse.y >= 430 && game->mouse.y <= 970) {
            draw_square(game, 1);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                calc_nbr(game, 1);
        }
    if (game->mouse.x >= 820 && game->mouse.x <= 1070)
        if (game->mouse.y >= 430 && game->mouse.y <= 970) {
            draw_square(game, 2);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                calc_nbr(game, 2);
        }
    if (game->mouse.x >= 1500 && game->mouse.x <= 1730)
        if (game->mouse.y >= 430 && game->mouse.y <= 970) {
            draw_square(game, 3);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                calc_nbr(game, 3);
        }
}

static void change_characters(game_t *game, int nbr)
{
    if (nbr == 1) {
        game->chac->rect_s.top = 0;
        game->chac->rect_s.left = 0;
        sfSprite_setTextureRect(game->chac->type_s, game->chac->rect_s);
        game->chac->rect_s.left = 300;
        sfSprite_setTextureRect(game->chac->type_s1, game->chac->rect_s);
        game->chac->rect_s.left += 300;
        sfSprite_setTextureRect(game->chac->type_s2, game->chac->rect_s);
    } else {
        game->chac->rect_s.top = 500;
        game->chac->rect_s.left = 0;
        sfSprite_setTextureRect(game->chac->type_s, game->chac->rect_s);
        game->chac->rect_s.left = 300;
        sfSprite_setTextureRect(game->chac->type_s1, game->chac->rect_s);
        game->chac->rect_s.left += 300;
        sfSprite_setTextureRect(game->chac->type_s2, game->chac->rect_s);
    }
}

void react_button_choose_s(game_t *game)
{
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    if (game->mouse.x >= 850 && game->mouse.x <= 965)
        if (game->mouse.y >= 300 && game->mouse.y <= 372)
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                game->chac->rect.top = 72;
                sfSprite_setTextureRect(game->chac->but_s, game->chac->rect);
                change_characters(game, 1);
            }
    if (game->mouse.x >= 965 && game->mouse.x <= 1080)
        if (game->mouse.y >= 300 && game->mouse.y <= 372)
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                change_characters(game, 2);
                game->chac->rect.top = 0;
                sfSprite_setTextureRect(game->chac->but_s, game->chac->rect);
            }
}
