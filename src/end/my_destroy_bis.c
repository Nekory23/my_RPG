/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** destroy all
*/

#include "rpg.h"

void destroy_play(game_t *game)
{
    sfMusic_destroy(game->play->village);
    sfTexture_destroy(game->play->map);
    sfSprite_destroy(game->play->map_s);
    sfTexture_destroy(game->play->map_b);
    sfSprite_destroy(game->play->map_sb);
    sfTexture_destroy(game->play->map1);
    sfSprite_destroy(game->play->map1_s);
    sfTexture_destroy(game->play->map1_b);
    sfSprite_destroy(game->play->map1_sb);
    sfTexture_destroy(game->play->map2);
    sfSprite_destroy(game->play->map2_s);
    sfTexture_destroy(game->play->map2_b);
    sfSprite_destroy(game->play->map2_sb);
    sfTexture_destroy(game->play->map_fight);
    sfSprite_destroy(game->play->map_fight_s);
    sfTexture_destroy(game->play->map_fight_b);
    sfSprite_destroy(game->play->map_fight_sb);
}

void destroy_inven_and_cursor(inven_t *inven, cursor_t *cursor)
{
    sfTexture_destroy(inven->inv);
    sfSprite_destroy(inven->inv_s);
    sfSprite_destroy(inven->chara_s);
    sfRectangleShape_destroy(cursor->cursor_m);
    sfTexture_destroy(cursor->cursor);
    sfTexture_destroy(inven->item);
    sfSprite_destroy(inven->item_s);
    sfTexture_destroy(inven->helmet);
    sfSprite_destroy(inven->helmet_s);
    sfTexture_destroy(inven->boot);
    sfSprite_destroy(inven->boot_s);
    sfTexture_destroy(inven->belt);
    sfSprite_destroy(inven->belt_s);
}

void destroy_quest_and_hud(quest_t *quest, hud_t *hud)
{
    sfTexture_destroy(quest->pnj);
    sfSprite_destroy(quest->pnj_s);
    sfTexture_destroy(quest->text);
    sfSprite_destroy(quest->text_s);
    sfRectangleShape_destroy(quest->but);
    sfRectangleShape_destroy(quest->but2);
    sfText_destroy(quest->resp);
    sfTexture_destroy(quest->bubble);
    sfSprite_destroy(quest->bubble_s);
    sfRectangleShape_destroy(hud->bkgd);
    sfText_destroy(hud->pv);
    sfText_destroy(hud->xp);
    sfText_destroy(hud->level);
    sfText_destroy(hud->def);
    sfText_destroy(hud->att);
    sfText_destroy(hud->stats);
}

void destroy_fight(fight_t *fight)
{
    sfMusic_destroy(fight->battle);
    sfTexture_destroy(fight->enemy);
    sfSprite_destroy(fight->enemy_s);
    sfRectangleShape_destroy(fight->bkgd);
    sfRectangleShape_destroy(fight->but1);
    sfRectangleShape_destroy(fight->but2);
    sfText_destroy(fight->text);
    sfSound_destroy(fight->hurt);
    sfSound_destroy(fight->death);
    sfSoundBuffer_destroy(fight->buff1);
    sfSoundBuffer_destroy(fight->buff2);
}
