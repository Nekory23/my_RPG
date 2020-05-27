/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision map 1
*/

#include "rpg.h"

static int check_river_final(sfVector2f pos)
{
    if (pos.x >= 679 && pos.x <= 1090)
        if (pos.y >= 108 && pos.y <= 318)
            return (TRUE);
    if (pos.x >= 1190 && pos.y >= 143 && pos.y <= 171)
        return  (TRUE);
    if (pos.x >= 1090 && pos.x <= 1095)
        if (pos.y >= 0 && pos.y <= 80)
            return (TRUE);
    return (FALSE);
}

static int check_river_bis(sfVector2f pos)
{
    if (pos.x >= 784 && (pos.y >= 409 && pos.y <= 528))
        return (TRUE);
    if (pos.x >= 854 && (pos.y >= 318 && pos.y <= 409))
        return (TRUE);
    if (check_river_final(pos))
        return (TRUE);
    return (FALSE);
}

static int check_river(sfVector2f pos)
{
    if (pos.x >= 875 && pos.x <= 1920)
        if (pos.y >= 598 && pos.y <= 703)
            return (TRUE);
    if (pos.x >= 847 && (pos.y >= 528 && pos.y <= 577))
        return (TRUE);
    if (check_river_bis(pos))
        return (TRUE);
    return (FALSE);
}

static int check_tree(sfVector2f pos)
{
    if (pos.x >= 973 && (pos.y >= 598 && pos.y <= 647))
        return (TRUE);
    if (pos.x >= 1673 && (pos.y >= 696 && pos.y <= 710))
        return (TRUE);
    if (pos.x >= 1210 && pos.x <= 1215)
        if (pos.y >= 135 && pos.y <= 170)
            return (TRUE);
    return (FALSE);
}

int check_map_one_r(sfVector2f pos)
{
    if (pos.x >= 1491 && (pos.y >= 0 && pos.y <= 367))
        return (TRUE);
    if (check_river(pos))
        return (TRUE);
    if (check_tree(pos))
        return (TRUE);
    return (FALSE);
}
