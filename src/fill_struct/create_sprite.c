/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create the character sprites
*/

#include "rpg.h"

void create_sprites_choose(charac_t *chac)
{
    chac->but = sfTexture_createFromFile("res/char/sex.png", NULL);
    chac->but_s = sfSprite_create();
    sfSprite_setTexture(chac->but_s, chac->but, sfTrue);
    chac->rect.left = 230;
    chac->rect.width = 230;
    chac->rect.height = 72;
    sfSprite_setTextureRect(chac->but_s, chac->rect);
    sfSprite_setPosition(chac->but_s, (sfVector2f) {850, 300});
}
