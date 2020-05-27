/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fill struct for the fight
*/

#include "rpg.h"

static void fill_struct_fight_bis(fight_t *fight, sfColor outline)
{
    sfFont *font = sfFont_createFromFile("res/fonts/main_font.TTF");

    fight->comp = 0;
    sfRectangleShape_setPosition(fight->bkgd, (sfVector2f) {920, 200});
    sfRectangleShape_setSize(fight->bkgd, (sfVector2f) {500, 400});
    fight->but1 = sfRectangleShape_copy(fight->bkgd);
    sfRectangleShape_setSize(fight->but1, (sfVector2f) {200, 100});
    sfRectangleShape_setOutlineThickness(fight->but1, 5);
    sfRectangleShape_setPosition(fight->but1, (sfVector2f) {960, 250});
    fight->but2 = sfRectangleShape_copy(fight->but1);
    sfRectangleShape_setPosition(fight->but2, (sfVector2f) {960, 450});
    fight->text = sfText_create();
    sfText_setFont(fight->text, font);
    sfText_setCharacterSize(fight->text, 60);
    sfText_setColor(fight->text, outline);
    fight->buff1 = sfSoundBuffer_createFromFile("res/music/sram_hurt.ogg");
    fight->hurt = sfSound_create();
    fight->buff2 = sfSoundBuffer_createFromFile("res/music/sram_death.ogg");
    fight->death = sfSound_create();
    sfSound_setBuffer(fight->hurt, fight->buff1);
    sfSound_setBuffer(fight->death, fight->buff2);
}

void fill_struct_fight(fight_t *fight)
{
    sfColor color = sfColor_fromRGBA(210, 105, 30, 200);
    sfColor outline = sfColor_fromRGBA(128, 0, 0, 200);

    fight->stats[0] = 30;
    fight->stats[1] = 13;
    fight->stats[2] = 8;
    fight->battle = sfMusic_createFromFile("res/music/battle.ogg");
    fight->enemy = sfTexture_createFromFile("res/char/sram/m/st.png", NULL);
    fight->rect.top = 520;
    fight->rect.width = 260;
    fight->rect.height = 260;
    fight->enemy_s = sfSprite_create();
    sfSprite_setTexture(fight->enemy_s, fight->enemy, sfTrue);
    sfSprite_setTextureRect(fight->enemy_s, fight->rect);
    sfSprite_setOrigin(fight->enemy_s, (sfVector2f) {130, 130});
    sfSprite_setPosition(fight->enemy_s, (sfVector2f) {450, 500});
    fight->bkgd = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(fight->bkgd, outline);
    sfRectangleShape_setOutlineThickness(fight->bkgd, 15);
    sfRectangleShape_setFillColor(fight->bkgd, color);
    fill_struct_fight_bis(fight, outline);
}
