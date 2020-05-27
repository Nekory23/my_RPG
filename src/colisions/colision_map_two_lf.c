/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map 2 left
*/

#include "rpg.h"

static int check_pos(sfVector2f pos)
{
    if (pos.x <= 1030 && pos.x >= 1025)
        if (pos.y >= 840 && pos.y <= 1080)
            return (TRUE);
    if (pos.x <= 260 && (pos.y >= 650 && pos.y <= 1080))
        return (TRUE);
    if (pos.x <= 670 && (pos.y >= 0 && pos.y <= 610))
        return (TRUE);
    return (FALSE);
}

int check_map_two_lf(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (pos.x <= 860 && (pos.y >= 760 && pos.y <= 820))
        return (TRUE);
    return (FALSE);
}
