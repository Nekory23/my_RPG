/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** change map
*/

#include "rpg.h"

void change_map_left(play_t *play)
{
    if (play->pos.x <= 50 && play->pos.y >= 750 && play->change_m == 0) {
        play->change_m = 1;
        play->pos.x = 1890;
    }
}

void change_map_right(play_t *play)
{
    int y = play->pos.y;
    int change = play->change_m;

    if (play->pos.x >= 1900 && (y >= 750 && y <= 880) && change == 1) {
        play->change_m = 0;
        play->pos.x = 60;
    }
}

void change_map_down(play_t *play)
{
    if (play->pos.y >= 1060 && play->change_m == 2) {
        if (play->pos.x <= 460)
            play->change_m = 1;
        if (play->pos.x >= 1050 && play->pos.x <= 1660)
            play->change_m = 0;
        play->pos.y = 60;
    }
}

void change_map_up(play_t *play)
{
    int x = play->pos.x;
    int change = play->change_m;

    if (play->pos.y <= 50 && (x >= 1050 && x <= 1660) && change == 0) {
        play->change_m = 2;
        play->pos.y = 1050;
        return;
    }
    if (change == 2 && play->pos.y <= 50) {
        play->change_m = 3;
        play->pos.x = 850;
        play->pos.y = 500;
        return;
    }
    if (change == 1 && play->pos.y <= 50 && play->pos.x >= 1400) {
        play->change_m = 2;
        play->pos.x = 400;
        play->pos.y = 1050;
    }
}
