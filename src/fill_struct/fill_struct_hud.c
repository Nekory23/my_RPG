/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fill_struct_for_hud
*/

#include "rpg.h"

static void fill_struct_hud_bis(hud_t *hud)
{
    hud->def = sfText_copy(hud->pv);
    sfText_setString(hud->def, "Defense :");
    hud->att = sfText_copy(hud->pv);
    sfText_setString(hud->att, "Attack :");
    sfText_setPosition(hud->xp, (sfVector2f) {580, 900});
    sfText_setPosition(hud->level, (sfVector2f) {580, 870});
    sfText_setPosition(hud->att, (sfVector2f) {900, 900});
    sfText_setPosition(hud->def, (sfVector2f) {900, 930});
}

void fill_struct_hud(hud_t *hud, sfFont *font)
{
    sfColor color = sfColor_fromRGBA(210, 105, 30, 200);
    sfColor outline = sfColor_fromRGBA(128, 0, 0, 200);
    sfColor text = sfColor_fromRGBA(128, 0, 0, 250);

    hud->bkgd = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->bkgd, (sfVector2f) {800, 200});
    sfRectangleShape_setPosition(hud->bkgd, (sfVector2f) {550, 850});
    sfRectangleShape_setOutlineColor(hud->bkgd, outline);
    sfRectangleShape_setOutlineThickness(hud->bkgd, 15);
    sfRectangleShape_setFillColor(hud->bkgd, color);
    hud->pv = sfText_create();
    sfText_setString(hud->pv, "PV :");
    sfText_setCharacterSize(hud->pv, 40);
    sfText_setPosition(hud->pv, (sfVector2f) {900, 870});
    sfText_setFont(hud->pv, font);
    sfText_setColor(hud->pv, text);
    hud->xp = sfText_copy(hud->pv);
    sfText_setString(hud->xp, "XP :");
    hud->level = sfText_copy(hud->pv);
    sfText_setString(hud->level, "Level :");
    fill_struct_hud_bis(hud);
}
