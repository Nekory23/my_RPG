/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map 1
*/

#include "rpg.h"

static int check_house_bis(sfVector2f pos)
{
    if (pos.y >= 570 && (pos.x >= 540 && pos.x <= 620))
        return (TRUE);
    if (pos.y >= 630 && (pos.x >= 620 && pos.x <= 680))
        return (TRUE);
    return (FALSE);
}

static int check_house(sfVector2f pos)
{
    if (pos.y >= 470 && (pos.x >= 340 && pos.x <= 460))
        return (TRUE);
    if (pos.y >= 530 && (pos.x >= 450 && pos.x <= 540))
        return (TRUE);
    if (check_house_bis(pos))
        return (TRUE);
    return (FALSE);
}

static int check_pos_bis(sfVector2f pos)
{
    if (pos.y >= 800 && (pos.x >= 1270 && pos.x <= 1920))
        return (TRUE);
    if (pos.y >= 710 && (pos.x >= 710 && pos.x <= 1270))
        return (TRUE);
    return (FALSE);
}

static int check_pos(sfVector2f pos)
{
    if (pos.y >= 100 && pos.y <= 101)
        if (pos.x >= 730 && pos.y <= 1040)
            return (TRUE);
    if (pos.y >= 190 && pos.y <= 200)
        if (pos.x >= 1390 && pos.x <= 1920)
            return (TRUE);
    if (check_pos_bis(pos))
        return (TRUE);
    return (FALSE);
}

int check_map_one_d(sfVector2f pos)
{
    if (check_house(pos))
        return (TRUE);
    if (check_pos(pos))
        return (TRUE);
    return (FALSE);
}
