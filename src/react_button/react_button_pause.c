/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** reaction for the buttons on the pause menu
*/

#include "rpg.h"

static void reset_colors(game_t *game)
{
    sfRectangleShape_setOutlineColor(game->pause->but, game->menu->box_c);
    sfRectangleShape_setOutlineColor(game->pause->but2, game->menu->box_c);
    sfRectangleShape_setOutlineColor(game->pause->but3, game->menu->box_c);
    sfText_setColor(game->pause->resume, game->menu->text_c);
    sfText_setColor(game->pause->quit, game->menu->text_c);
    sfText_setColor(game->pause->main, game->menu->text_c);
}

static void change_colors(game_t *game, int but)
{
    switch (but) {
    case 1 :
        sfRectangleShape_setOutlineColor(game->pause->but, game->menu->text_c);
        sfText_setColor(game->pause->resume, game->menu->box_c);
        break;
    case 2 :
        sfRectangleShape_setOutlineColor(game->pause->but2, game->menu->text_c);
        sfText_setColor(game->pause->main, game->menu->box_c);
        break;
    case 3 :
        sfRectangleShape_setOutlineColor(game->pause->but3, game->menu->text_c);
        sfText_setColor(game->pause->quit, game->menu->box_c);
        break;
    }
}

void react_button_pause(game_t *gm)
{
    gm->mouse = sfMouse_getPositionRenderWindow(gm->win);
    reset_colors(gm);
    if (gm->mouse.x >= (gm->pause->pos.x - 5) && gm->mouse.x <= 930)
        if (gm->mouse.y >= (gm->pause->pos.y - 5) && gm->mouse.y <= 435) {
            change_colors(gm, 1);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                gm->ret = GAME;
        }
    if (gm->mouse.x >= (gm->pause->pos2.x - 5) && gm->mouse.x <= 1010)
        if (gm->mouse.y >= (gm->pause->pos2.y - 5) && gm->mouse.y <= 535) {
            change_colors(gm, 2);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                gm->ret = MAIN;
        }
    if (gm->mouse.x >= (gm->pause->pos3.x - 5) && gm->mouse.x <= 1010)
        if (gm->mouse.y >= (gm->pause->pos3.y - 5) && gm->mouse.y <= 635) {
            change_colors(gm, 3);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                gm->ret = END;
        }
}
