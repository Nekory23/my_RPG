/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map zero
*/

#include "rpg.h"

static int check_pos(sfVector2f pos)
{
    if (pos.y >= 980 && (pos.x >= 0 && pos.x <= 1920))
        return (TRUE);
    if (pos.y >= 855 && (pos.x >= 0 && pos.x <= 620))
        return (TRUE);
    if (pos.y >= 830 && (pos.x >= 1440 && pos.x <= 1560))
        return (TRUE);
    return (FALSE);
}

static int check_pos_bis(sfVector2f pos)
{
    if (pos.y >= 930 && (pos.x >= 1380 && pos.x <= 1920))
        return (TRUE);
    if (pos.y >= 220 && pos.y <= 221)
        if (pos.x >= 0 && pos.x <= 1230)
            return (TRUE);
    if (pos.y >= 735 && (pos.x >= 740 && pos.x <= 1060))
        return (TRUE);
    return (FALSE);
}

int check_map_zero_d(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}
