/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map one left
*/

#include "rpg.h"

static int check_pos_bis(sfVector2f pos)
{
    if (pos.x <= 460 && (pos.y >= 450 && pos.y <= 540))
        return (TRUE);
    if (pos.x <= 350 && (pos.y >= 0 && pos.y <= 470))
        return (TRUE);
    if (pos.x <= 1380 && pos.x >= 1375)
        if (pos.y >= 0 && pos.y <= 50)
            return (TRUE);
    return (FALSE);
}

static int check_pos(sfVector2f pos)
{
    if (pos.x <= 1280 && pos.x >= 1275)
        if (pos.y >= 800 && pos.y <= 770)
            return (TRUE);
    if (pos.x <= 690 && (pos.y >= 630 && pos.y <= 740))
        return (TRUE);
    if (pos.x <= 640 && (pos.y >= 540 && pos.y <= 630))
        return (TRUE);
    return (FALSE);
}

int check_map_one_lf(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}
