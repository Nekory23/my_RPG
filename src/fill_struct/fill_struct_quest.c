/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fill the quest structure
*/

#include "rpg.h"

static void fill_struct_quest_bis(quest_t *quest, sfFont *font)
{
    quest->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(quest->but, sfBlack);
    sfRectangleShape_setOutlineThickness(quest->but, 5);
    sfRectangleShape_setFillColor(quest->but, sfTransparent);
    quest->but2	= sfRectangleShape_copy(quest->but);
    quest->resp = sfText_create();
    sfText_setCharacterSize(quest->resp, 90);
    sfText_setColor(quest->resp, sfBlack);
    sfText_setFont(quest->resp, font);
    quest->check = 0;
    quest->kill = 0;
    quest->claim = 0;
}

void fill_struct_quest(quest_t *quest, sfFont *font)
{
    quest->status = 0;
    quest->pnj = sfTexture_createFromFile("res/char/pnj1.png", NULL);
    quest->pnj_s = sfSprite_create();
    sfSprite_setTexture(quest->pnj_s, quest->pnj, sfTrue);
    sfSprite_setPosition(quest->pnj_s, (sfVector2f) {1800, 380});
    sfSprite_setScale(quest->pnj_s, (sfVector2f) {-1.25, 1.25});
    quest->bubble = sfTexture_createFromFile("res/pics/bubble.png", NULL);
    quest->bubble_s = sfSprite_create();
    sfSprite_setTexture(quest->bubble_s, quest->bubble, sfTrue);
    quest->rect_b.width = 33;
    quest->rect_b.height = 44;
    sfSprite_setTextureRect(quest->bubble_s, quest->rect_b);
    quest->pos_b.x = 1705;
    quest->pos_b.y = 340;
    sfSprite_setPosition(quest->bubble_s, quest->pos_b);
    quest->text = sfTexture_createFromFile("res/quest/farmer_quest.png", NULL);
    quest->text_s = sfSprite_create();
    sfSprite_setTexture(quest->text_s, quest->text, sfTrue);
    sfSprite_setPosition(quest->text_s, (sfVector2f) {400, 240});
    fill_struct_quest_bis(quest, font);
}
