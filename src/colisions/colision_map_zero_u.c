/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map zero up
*/

#include "rpg.h"

static int check_pos(sfVector2f pos)
{
    if (pos.y >= 749 && pos.y <= 750)
        if (pos.x >= 0 && pos.x <= 740)
            return (TRUE);
    if (pos.y >= 689 && pos.y <= 690)
        if (pos.x >= 740 && pos.x <= 830)
            return (TRUE);
    if (pos.y >= 449 && pos.y <= 450)
        if (pos.x >= 0 && pos.x <= 980)
            return (TRUE);
    return (FALSE);
}

static int check_pos_bis(sfVector2f pos)
{
    if (pos.y >= 369 && pos.y <= 370)
        if (pos.x >= 980 && pos.x <= 1270)
            return (TRUE);
    if (pos.y >= 509 && pos.y <= 510)
        if (pos.x >= 920 && pos.x <= 970)
            return (TRUE);
    if (pos.y >= 410 && pos.y <= 409)
        if (pos.x >= 1560 && pos.x <= 1920)
            return (TRUE);
    return (FALSE);
}

int check_map_zero_u(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}
