/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** draw_quest_bubble
*/

#include "rpg.h"

static void move_bubble(quest_t *quest)
{
    if (quest->check == 0) {
        sfSprite_move(quest->bubble_s, (sfVector2f) {0, -1});
        quest->pos_b.y -= 0.1;
        if (quest->pos_b.y <= 337) {
            quest->check = 1;
            return;
        }
    }
    if (quest->check == 1) {
        sfSprite_move(quest->bubble_s, (sfVector2f) {0, 1});
        quest->pos_b.y += 0.1;
        if (quest->pos_b.y >= 340) {
            quest->check = 0;
            return;
        }
    }
}

void draw_quest_bubble(int status, game_t *game)
{
    switch (status) {
    case 0 :
        sfRenderWindow_drawSprite(game->win, game->quest->bubble_s, NULL);
        move_bubble(game->quest);
        break;
    case 1 :
        game->quest->rect_b.left = 66;
        sfSprite_setTextureRect(game->quest->bubble_s, game->quest->rect_b);
        sfRenderWindow_drawSprite(game->win, game->quest->bubble_s, NULL);
        move_bubble(game->quest);
        break;
    case 2 :
        game->quest->rect_b.left = 33;
        sfSprite_setTextureRect(game->quest->bubble_s, game->quest->rect_b);
        sfRenderWindow_drawSprite(game->win, game->quest->bubble_s, NULL);
        move_bubble(game->quest);
        break;
    }
}
