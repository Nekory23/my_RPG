/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map 2
*/

#include "rpg.h"

static int check_house(sfVector2f pos)
{
    if (pos.x >= 1116 && (pos.y >= 644 && pos.y <= 707))
        return (TRUE);
    if (pos.x >= 1011 && (pos.y >= 581 && pos.y <= 644))
        return (TRUE);
    if (pos.x >= 913 && (pos.y >= 0 && pos.y <= 546))
        return (TRUE);
    return (FALSE);
}

static int check_tree(sfVector2f pos)
{
    if (pos.x >= 739 && pos.x <= 850)
        if (pos.y >= 777 && pos.y <= 805)
            return (TRUE);
    if (pos.x >= 1312 && (pos.y >= 707 && pos.y <= 1080))
        return (TRUE);
    return (FALSE);
}

int check_map_two_r(sfVector2f pos)
{
    if (pos.x >= 535 && pos.x <= 1020)
        if (pos.y >= 845 && pos.y <= 1080)
            return (TRUE);
    if (check_tree(pos))
        return (TRUE);
    if (check_house(pos))
        return (TRUE);
    return (FALSE);
}
