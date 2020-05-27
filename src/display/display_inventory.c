/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display the inventory
*/

#include "rpg.h"

static void get_event(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyR))
        game->ret = GAME;
}

static void draw_the_chara(inven_t *inven, sfRenderWindow *win, int chara)
{
    sfRenderWindow_drawSprite(win, inven->inv_s, NULL);
    inven->inv_r.left = 0;
    inven->inv_r.top = 260;
    inven->inv_r.width = 260;
    inven->inv_r.height = 260;
    sfSprite_setTextureRect(inven->chara_s, inven->inv_r);
    sfSprite_setScale(inven->chara_s, (sfVector2f) {2.5, 2.5});
    if (chara == 1 || chara == 4)
        sfSprite_setPosition(inven->chara_s, (sfVector2f) {850, 450});
    else
        sfSprite_setPosition(inven->chara_s, (sfVector2f) {850, 600});
    sfRenderWindow_drawSprite(win, inven->chara_s, NULL);
}

void display_inventory(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        get_event(game);
        if (game->ret == GAME)
            break;
        game->inven->chara_s = sfSprite_copy(game->play->player_s);
        draw_player(game);
        draw_the_chara(game->inven, game->win, game->chara);
        interact_inv(game->inven, game);
        if (game->quest->status == 3) {
            game->inven->slot[0][0] = 1;
            sfRenderWindow_drawSprite(game->win, game->inven->item_s, NULL);
        }
        sfRenderWindow_drawSprite(game->win, game->inven->helmet_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->inven->boot_s, NULL);
        sfRenderWindow_drawSprite(game->win, game->inven->belt_s, NULL);
        display_cursor(game);
        sfRenderWindow_display(game->win);
    }
}
