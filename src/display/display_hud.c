/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display of the hud
*/

#include <stdlib.h>
#include "rpg.h"

static char *trans_nb_to_char(int nb)
{
    int i = 0;
    char *str;

    if (nb < 0) {
        str = "--";
        return (str);
    }
    str = malloc(sizeof(char) * (nb + 3));
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (; nb; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

static void draw_stats(hud_t *hud, sfRenderWindow *win)
{
    char *xp = my_strcat(trans_nb_to_char(hud->stat[2]), "/");

    xp = my_strcat(xp, trans_nb_to_char(hud->stat[5]));
    hud->stats = sfText_copy(hud->pv);
    sfText_setString(hud->stats, trans_nb_to_char(hud->stat[0]));
    sfText_setPosition(hud->stats, (sfVector2f) {1050, 870});
    sfRenderWindow_drawText(win, hud->stats, NULL);
    sfText_setString(hud->stats, trans_nb_to_char(hud->stat[1]));
    sfText_setPosition(hud->stats, (sfVector2f) {730, 870});
    sfRenderWindow_drawText(win, hud->stats, NULL);
    sfText_setString(hud->stats, xp);
    sfText_setPosition(hud->stats, (sfVector2f) {730, 900});
    sfRenderWindow_drawText(win, hud->stats, NULL);
    sfText_setString(hud->stats, trans_nb_to_char(hud->stat[3]));
    sfText_setPosition(hud->stats, (sfVector2f) {1050, 930});
    sfRenderWindow_drawText(win, hud->stats, NULL);
    sfText_setString(hud->stats, trans_nb_to_char(hud->stat[4]));
    sfText_setPosition(hud->stats, (sfVector2f) {1050, 900});
    sfRenderWindow_drawText(win, hud->stats, NULL);
}

void display_hud(hud_t *hud, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, hud->bkgd, NULL);
    sfRenderWindow_drawText(win, hud->pv, NULL);
    sfRenderWindow_drawText(win, hud->xp, NULL);
    sfRenderWindow_drawText(win, hud->level, NULL);
    sfRenderWindow_drawText(win, hud->def, NULL);
    sfRenderWindow_drawText(win, hud->att, NULL);
    draw_stats(hud, win);
}
