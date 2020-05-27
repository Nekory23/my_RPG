/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** destroy everything
*/

#include "rpg.h"

static void destroy_htp(game_t *game)
{
    sfTexture_destroy(game->how->scroll);
    sfSprite_destroy(game->how->scroll_s);
    sfText_destroy(game->how->text);
    sfText_destroy(game->how->htp);
    sfText_destroy(game->how->ret);
    sfRectangleShape_destroy(game->how->but);
}

static void destroy_menu(game_t *game)
{
    sfMusic_destroy(game->menu->music);
    sfRectangleShape_destroy(game->menu->but);
    sfRectangleShape_destroy(game->menu->but2);
    sfRectangleShape_destroy(game->menu->but3);
    sfText_destroy(game->menu->text);
    sfText_destroy(game->menu->play);
    sfText_destroy(game->menu->quit);
    sfText_destroy(game->menu->htp);
    sfFont_destroy(game->menu->font);
    sfTexture_destroy(game->menu->bgd);
    sfSprite_destroy(game->menu->bgd_s);
}

static void destroy_pause(game_t *game)
{
    sfText_destroy(game->pause->pause_t);
    sfText_destroy(game->pause->resume);
    sfText_destroy(game->pause->quit);
    sfText_destroy(game->pause->main);
    sfRectangleShape_destroy(game->pause->but);
    sfRectangleShape_destroy(game->pause->but2);
    sfRectangleShape_destroy(game->pause->but3);
}

static void destroy_chara(game_t *game)
{
    sfTexture_destroy(game->chac->type);
    sfSprite_destroy(game->chac->type_s);
    sfSprite_destroy(game->chac->type_s1);
    sfSprite_destroy(game->chac->type_s2);
    sfTexture_destroy(game->chac->but);
    sfSprite_destroy(game->chac->but_s);
    sfRectangleShape_destroy(game->chac->but1);
    sfRectangleShape_destroy(game->chac->but2);
    sfRectangleShape_destroy(game->chac->choice);
    sfText_destroy(game->chac->choose);
    sfText_destroy(game->chac->type_t);
    sfText_destroy(game->chac->caract);
}

void my_destroy(game_t *game)
{
    destroy_menu(game);
    destroy_htp(game);
    destroy_pause(game);
    destroy_chara(game);
    destroy_play(game);
    destroy_inven_and_cursor(game->inven, game->cursor);
    destroy_quest_and_hud(game->quest, game->hud);
    destroy_fight(game->fight);
    sfRenderWindow_destroy(game->win);
}
