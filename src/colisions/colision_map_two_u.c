/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map 2 up
*/

#include "rpg.h"

static int check_pos(sfVector2f pos)
{
    if (pos.y >= 699 && pos.y <= 700)
        if (pos.x >= 1180 && pos.x <= 1920)
            return (TRUE);
    if (pos.y >= 659 && pos.y <= 600)
        if (pos.x >= 1071 && pos.x <= 1180)
            return (TRUE);
    if (pos.y >= 639 && pos.y <= 640)
        if (pos.x >= 1020 && pos.x <= 1150)
            return (TRUE);
    return (FALSE);
}

static int check_pos_bis(sfVector2f pos)
{
    if (pos.y >= 579 && pos.y <= 580)
        if (pos.x >= 940 && pos.x <= 1920)
            return (TRUE);
    if (pos.y >= 839 && pos.y <= 840)
        if (pos.x >= 780 && pos.x <= 830)
            return (TRUE);
    if (pos.y >= 649 && pos.y <= 650)
        if (pos.x >= 0 && pos.x <= 680)
            return (TRUE);
    return (FALSE);
}

int check_map_two_u(sfVector2f pos)
{
    if (check_pos(pos))
        return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}
