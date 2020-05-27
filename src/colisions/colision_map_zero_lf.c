/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map zero left
*/

#include "rpg.h"

static int check_pos(sfVector2f pos)
{
    if (pos.x <= 1225 && (pos.y >= 300 && pos.y <= 340))
        return (TRUE);
    if (pos.x <= 1080 && (pos.y >= 800 && pos.y <= 980))
        return (TRUE);
    if (pos.x <= 860 && (pos.y >= 0 && pos.y <= 670))
        return (TRUE);
    return (FALSE);
}

static int check_pos_bis(sfVector2f pos)
{
    if (pos.x <= 940 && (pos.y >= 370 && pos.y <= 410))
        return (TRUE);
    if (pos.x <= 1130 && (pos.y >= 0 && pos.y <= 370))
        return (TRUE);
    return (FALSE);
}

int check_map_zero_lf(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}
