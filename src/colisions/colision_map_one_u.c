/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map one up
*/

#include "rpg.h"

static int check_pos_bis(sfVector2f pos)
{
    if (pos.y >= 659 && pos.y <= 660)
        if (pos.x >= 980 && pos.x <= 1459)
            return (TRUE);
    if (pos.y >= 599 && pos.y <= 600)
        if (pos.x >= 860 && pos.x <= 980)
            return (TRUE);
    if (pos.y >= 0 && pos.y <= 30)
        if (pos.x >= 0 && pos.x <= 1090)
            return (TRUE);
    return (FALSE);
}

static int check_pos(sfVector2f pos)
{
    if (pos.y >= 739 && pos.y <= 740)
        if (pos.x >= 1690 && pos.x <= 1920)
            return (TRUE);
    if (pos.y >= 660 && pos.y <= 700)
        if (pos.x >= 1460 && pos.x <= 1690)
            return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}

static int check_pos_final(sfVector2f pos)
{
    if (pos.y >= 529 && pos.y <= 530)
        if (pos.x >= 790 && pos.x <= 859)
            return (TRUE);
    if (pos.y >= 319 && pos.y <= 320)
        if (pos.x >= 690 && pos.x <= 860)
            return (TRUE);
    if (pos.y >= 89 && pos.y <= 90)
        if (pos.x >= 1150 && pos.x <= 1340)
            return (TRUE);
    return (FALSE);
}

int check_map_one_u(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (check_pos_final(pos))
        return (TRUE);
    return (FALSE);
}
