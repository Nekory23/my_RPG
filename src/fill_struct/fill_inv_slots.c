/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fill the slots of the inventory (+ choose your character)
*/

#include "rpg.h"

static void prepare_item(inven_t *inven)
{
    inven->item = sfTexture_createFromFile("res/items/HammerB.png", NULL);
    inven->item_s = sfSprite_create();
    sfSprite_setTexture(inven->item_s, inven->item, sfTrue);
    sfSprite_setPosition(inven->item_s, inven->pos[0][0]);
    sfSprite_setScale(inven->item_s, (sfVector2f) {1.5, 1.5});
    inven->helmet = sfTexture_createFromFile("res/items/HelmetB.png", NULL);
    inven->helmet_s = sfSprite_create();
    sfSprite_setTexture(inven->helmet_s, inven->helmet, sfTrue);
    sfSprite_setPosition(inven->helmet_s, inven->pos_a[1]);
    sfSprite_setScale(inven->helmet_s, (sfVector2f) {1.25, 1.25});
    inven->boot = sfTexture_createFromFile("res/items/BootsB.png", NULL);
    inven->boot_s = sfSprite_create();
    sfSprite_setTexture(inven->boot_s, inven->boot, sfTrue);
    sfSprite_setPosition(inven->boot_s, inven->pos_a[3]);
    sfSprite_setScale(inven->boot_s, (sfVector2f) {1.25, 1.25});
    inven->belt = sfTexture_createFromFile("res/items/BeltB.png", NULL);
    inven->belt_s = sfSprite_create();
    sfSprite_setTexture(inven->belt_s, inven->belt, sfTrue);
    sfSprite_setPosition(inven->belt_s, inven->pos_a[2]);
    sfSprite_setScale(inven->belt_s, (sfVector2f) {1.25, 1.25});
}

static void fill_pos_ter(inven_t *inven)
{
    inven->pos[4][2].x = 1190;
    inven->pos[4][2].y = 615;
    inven->pos[4][3].x = 1280;
    inven->pos[4][3].y = 615;
    inven->pos[5][0].x = 1023;
    inven->pos[5][0].y = 700;
    inven->pos[5][1].x = 1110;
    inven->pos[5][1].y = 700;
    inven->pos[5][2].x = 1190;
    inven->pos[5][2].y = 700;
    inven->pos[5][3].x = 1280;
    inven->pos[5][3].y = 700;
    inven->pos_a[0].x = 600;
    inven->pos_a[0].y = 300;
    inven->pos_a[1].x = 600;
    inven->pos_a[1].y = 415;
    inven->pos_a[2].x = 600;
    inven->pos_a[2].y = 485;
    inven->pos_a[3].x = 600;
    inven->pos_a[3].y = 565;
    prepare_item(inven);
}

static void fill_pos_bis(inven_t *inven)
{
    inven->pos[2][2].x = 1190;
    inven->pos[2][2].y = 450;
    inven->pos[2][3].x = 1280;
    inven->pos[2][3].y = 450;
    inven->pos[3][0].x = 1023;
    inven->pos[3][0].y = 530;
    inven->pos[3][1].x = 1110;
    inven->pos[3][1].y = 530;
    inven->pos[3][2].x = 1190;
    inven->pos[3][2].y = 530;
    inven->pos[3][3].x = 1280;
    inven->pos[3][3].y = 530;
    inven->pos[4][0].x = 1023;
    inven->pos[4][0].y = 615;
    inven->pos[4][1].x = 1110;
    inven->pos[4][1].y = 615;
    fill_pos_ter(inven);
}

void fill_pos_inv(inven_t *inven)
{
    inven->pos[0][0].x = 1023;
    inven->pos[0][0].y = 280;
    inven->pos[0][1].x = 1110;
    inven->pos[0][1].y = 280;
    inven->pos[0][2].x = 1190;
    inven->pos[0][2].y = 280;
    inven->pos[0][3].x = 1280;
    inven->pos[0][3].y = 280;
    inven->pos[1][0].x = 1023;
    inven->pos[1][0].y = 365;
    inven->pos[1][1].x = 1110;
    inven->pos[1][1].y = 365;
    inven->pos[1][2].x = 1190;
    inven->pos[1][2].y = 365;
    inven->pos[1][3].x = 1280;
    inven->pos[1][3].y = 365;
    inven->pos[2][0].x = 1023;
    inven->pos[2][0].y = 450;
    inven->pos[2][1].x = 1110;
    inven->pos[2][1].y = 450;
    fill_pos_bis(inven);
}

void fill_save(game_t *game)
{
    game->chara = 0;
    for (int i = 0; i != 6; i++)
        for (int j = 0; j != 4; j++)
            game->inven->slot[i][j] = 0;
    for (int i = 0; i != 4; i++)
        game->inven->armor[i] = 0;
}
