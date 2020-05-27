/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check colision in y
*/

#include "rpg.h"

static int check_colision_down(play_t *play)
{
    if (play->change_m == 0)
        if (check_map_zero_d(play->pos))
            return (TRUE);
    if (play->change_m == 1)
        if (check_map_one_d(play->pos))
            return (TRUE);
    if (play->change_m == 2)
        if (check_map_two_d(play->pos))
            return (TRUE);
    return (FALSE);
}

static int check_colision_up(play_t *play)
{
    if (play->change_m == 0)
        if (check_map_zero_u(play->pos))
            return (TRUE);
    if (play->change_m == 1)
        if (check_map_one_u(play->pos))
            return (TRUE);
    if (play->change_m == 2)
        if (check_map_two_u(play->pos))
            return (TRUE);
    return (FALSE);
}

static int check_fight_end(play_t *play)
{
    if (play->end_fight == 1)
        if (play->pos.x >= 0 && play->pos.y <= 1920)
            if (play->pos.y >= 0 && play->pos.y <= 60)
                return (TRUE);
    return (FALSE);
}

int check_colision_y(play_t *play, int id)
{
    if (id == 0)
        if (check_colision_down(play))
            return (TRUE);
    if (id == 1)
        if (check_colision_up(play) || check_fight_end(play))
            return (TRUE);
    return (FALSE);
}
