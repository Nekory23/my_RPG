/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision in x
*/

#include "rpg.h"

static int check_colision_right(play_t *play)
{
    if (play->change_m == 0)
        if (check_map_zero_r(play->pos))
            return (TRUE);
    if (play->change_m == 1)
        if (check_map_one_r(play->pos))
            return (TRUE);
    if (play->change_m == 2)
        if (check_map_two_r(play->pos))
            return (TRUE);
    return (FALSE);
}

static int check_colision_left(play_t *play)
{
    if (play->change_m == 0)
        if (check_map_zero_lf(play->pos))
            return (TRUE);
    if (play->change_m == 1)
        if (check_map_one_lf(play->pos))
            return (TRUE);
    if (play->change_m == 2)
        if (check_map_two_lf(play->pos))
            return (TRUE);
    return (FALSE);
}

int check_colision_x(play_t *play, int id)
{
    if (id == 0)
        if (check_colision_right(play))
            return (TRUE);
    if (id == 1)
        if (check_colision_left(play))
            return (TRUE);
    return (FALSE);
}

