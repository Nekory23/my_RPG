/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colison
*/

#include "rpg.h"

static int check_top(sfVector2f pos)
{
    if (pos.x >= 1525 && (pos.y >= 179 && pos.y <= 395))
        return (TRUE);
    if (pos.x >= 1410 && (pos.y >= 0 && pos.y <= 179))
        return (TRUE);
    return (FALSE);
}

static int check_tower(sfVector2f pos)
{
    if (pos.x >= 1330 && (pos.y >= 822 && pos.y <= 983))
        return (TRUE);
    return (FALSE);
}

static int check_left(sfVector2f pos)
{
    if (pos.y >= 766 && pos.y <= 850)
        if (pos.x >= 620 && pos.x <= 717)
            return (TRUE);
    return (FALSE);
}

static int check_png(sfVector2f pos)
{
    if (pos.x >= 1645 && pos.y >= (470 && pos.y <= 490))
        return (TRUE);
    if (check_top(pos))
        return (TRUE);
    if (check_left(pos))
        return (TRUE);
    return (FALSE);
}

int check_map_zero_r(sfVector2f pos)
{
    if (pos.x >= 1670)
        return (TRUE);
    if (check_tower(pos))
        return (TRUE);
    if (check_png(pos))
        return (TRUE);
    return (FALSE);
}
