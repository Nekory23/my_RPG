/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map 2
*/

#include "rpg.h"

static int check_pos(sfVector2f pos)
{
    if (pos.y >= 800 && pos.y <= 801)
        if (pos.x >= 540 && pos.x <= 685)
            return (TRUE);
    if (pos.y >= 540 && pos.y <= 541)
        if (pos.x >= 0 && pos.x <= 660)
            return (TRUE);
    return (FALSE);
}

int check_map_two_d(sfVector2f pos)
{
    if (pos.y >= 840 && (pos.x >= 530 && pos.x <= 960))
        return (TRUE);
    if (pos.y >= 760 && (pos.x >= 780 && pos.x <= 860))
        return (TRUE);
    if (check_pos(pos))
        return (TRUE);
    return (FALSE);
}
