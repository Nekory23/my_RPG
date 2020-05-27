/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create the buttons
*/

#include "rpg.h"

void create_button_main(main_t *menu)
{
    menu->but = sfRectangleShape_create();
    menu->pos.x = 1085;
    menu->pos.y = 255;
    sfRectangleShape_setPosition(menu->but, menu->pos);
    menu->size.x = 170;
    menu->size.y = 100;
    sfRectangleShape_setSize(menu->but, menu->size);
    sfRectangleShape_setOutlineColor(menu->but, menu->box_c);
    sfRectangleShape_setOutlineThickness(menu->but, 5);
    sfRectangleShape_setFillColor(menu->but, sfTransparent);
    menu->but2 = sfRectangleShape_copy(menu->but);
    menu->pos2.x = 1480;
    menu->pos2.y = 255;
    sfRectangleShape_setPosition(menu->but2, menu->pos2);
    menu->but3 = sfRectangleShape_copy(menu->but);
    menu->pos3.x = 1180;
    menu->pos3.y = 405;
    sfRectangleShape_setPosition(menu->but3, menu->pos3);
    menu->size3.x = 400;
    menu->size3.y = 100;
    sfRectangleShape_setSize(menu->but3, menu->size3);
}

void create_button_htp(htp_t *how, main_t *menu)
{
    how->but = sfRectangleShape_create();
    how->pos.x = 850;
    how->pos.y = 730;
    sfRectangleShape_setPosition(how->but, how->pos);
    how->size.x = 180;
    how->size.y = 70;
    sfRectangleShape_setSize(how->but, how->size);
    sfRectangleShape_setOutlineColor(how->but, menu->box_c);
    sfRectangleShape_setOutlineThickness(how->but, 5);
    sfRectangleShape_setFillColor(how->but, sfTransparent);
}

static void create_button_pause_bis(game_t *game)
{
    game->pause->but3 = sfRectangleShape_copy(game->pause->but);
    game->pause->pos3.x = 740;
    game->pause->pos3.y = 550;
    sfRectangleShape_setPosition(game->pause->but3, game->pause->pos3);
    game->pause->size3.x = 265;
    game->pause->size3.y = 80;
    sfRectangleShape_setSize(game->pause->but3, game->pause->size3);
}

void create_button_pause(game_t *game)
{
    game->pause->but = sfRectangleShape_create();
    game->pause->pos.x = 740;
    game->pause->pos.y = 350;
    sfRectangleShape_setPosition(game->pause->but, game->pause->pos);
    game->pause->size.x = 185;
    game->pause->size.y = 80;
    sfRectangleShape_setSize(game->pause->but, game->pause->size);
    sfRectangleShape_setOutlineColor(game->pause->but, game->menu->box_c);
    sfRectangleShape_setOutlineThickness(game->pause->but, 5);
    sfRectangleShape_setFillColor(game->pause->but, sfTransparent);
    game->pause->but2 = sfRectangleShape_copy(game->pause->but);
    game->pause->pos2.x = 740;
    game->pause->pos2.y = 450;
    sfRectangleShape_setPosition(game->pause->but2, game->pause->pos2);
    game->pause->size2.x = 265;
    game->pause->size2.y = 80;
    sfRectangleShape_setSize(game->pause->but2, game->pause->size2);
    create_button_pause_bis(game);
}

void create_button_choose(charac_t *chac)
{
    chac->choice = sfRectangleShape_create();
    chac->size_c.x = 240;
    chac->size_c.y = 440;
    sfRectangleShape_setSize(chac->choice, chac->size_c);
    sfRectangleShape_setOutlineColor(chac->choice, sfTransparent);
    sfRectangleShape_setOutlineThickness(chac->choice, 5);
    sfRectangleShape_setFillColor(chac->choice, sfTransparent);
}
