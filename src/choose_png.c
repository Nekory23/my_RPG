/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** choose you character
*/

#include "rpg.h"

static void give_stats(hud_t *hud, int chara)
{
    for (int i = 0; i != 5; i++)
        hud->stat[i] = 0;
    hud->stat[1] = 1;
    hud->stat[5] = 15;
    if (chara == 1 || chara == 4) {
        hud->stat[0] = 45;
        hud->stat[3] = 7;
        hud->stat[4] = 8;
    }
    else if (chara == 2 || chara == 5) {
        hud->stat[0] = 30;
        hud->stat[3] = 7;
        hud->stat[4] = 12;
    } else {
        hud->stat[0] = 30;
        hud->stat[3] = 13;
        hud->stat[4] = 8;
    }
}

static void create_chara_sprite(play_t *play)
{
    play->player_s = sfSprite_create();
    play->rect.top = 0;
    play->rect.height = 260;
    play->rect.width = 260;
    sfSprite_setTexture(play->player_s, play->player, sfTrue);
    sfSprite_setTextureRect(play->player_s, play->rect);
    play->origin.x = 130;
    play->origin.y = 130;
    sfSprite_setOrigin(play->player_s, play->origin);
    play->pos.x = 1270;
    play->pos.y = 800;
    sfSprite_setPosition(play->player_s, play->pos);
}

static void create_chara_texture(int nb, play_t *play)
{
    switch (nb) {
    case 1 :
        play->player = sfTexture_createFromFile("res/char/cra/m/st.png", NULL);
        break;
    case 2 :
        play->player = sfTexture_createFromFile("res/char/iop/m/st.png", NULL);
        break;
    case 3 :
        play->player = sfTexture_createFromFile("res/char/sram/m/st.png", NULL);
        break;
    case 4 :
        play->player = sfTexture_createFromFile("res/char/cra/f/st.png", NULL);
        break;
    case 5 :
        play->player = sfTexture_createFromFile("res/char/iop/f/st.png", NULL);
        break;
    case 6 :
        play->player = sfTexture_createFromFile("res/char/sram/f/st.png", NULL);
        break;
    }
    create_chara_sprite(play);
}

void choose_player(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win)) {
        event_close(game);
        if (game->chara != 0) {
            create_chara_texture(game->chara, game->play);
            give_stats(game->hud, game->chara);
            break;
        }
        react_button_choose_s(game);
        react_button_choose_c(game);
        sfRenderWindow_clear(game->win, sfBlack);
        draw_choose_png(game);
        sfRenderWindow_display(game->win);
    }
}
