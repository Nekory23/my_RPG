
/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** fill struct play
*/

#include "rpg.h"

static void fill_pos(play_t *play)
{
    play->posm.x = 0;
    play->posm.y = 0;
    play->posmb.x = 0;
    play->posmb.y = 215;
    play->posm1.y = -10;
    play->posm1.x = 325;
    play->posm2.x = 205;
    play->posm2.y = 560;
    play->posfight.x = 145;
    play->posfight.y = 95;
    sfSprite_setPosition(play->map_s, play->posm);
    sfSprite_setPosition(play->map_sb, play->posmb);
    sfSprite_setPosition(play->map1_s, play->posm);
    sfSprite_setPosition(play->map1_sb, play->posm1);
    sfSprite_setPosition(play->map2_s, play->posm);
    sfSprite_setPosition(play->map2_sb, play->posm2);
    sfSprite_setPosition(play->map_fight_s, play->posm);
    sfSprite_setPosition(play->map_fight_sb, play->posfight);
}

static void fill_map(play_t *play)
{
    play->map = sfTexture_createFromFile("res/map/milieu.png", NULL);
    play->map_s = sfSprite_create();
    sfSprite_setTexture(play->map_s, play->map, sfTrue);
    play->map1 = sfTexture_createFromFile("res/map/gauche.png", NULL);
    play->map1_s = sfSprite_create();
    sfSprite_setTexture(play->map1_s, play->map1, sfTrue);
    play->map2 = sfTexture_createFromFile("res/map/haut.png", NULL);
    play->map2_s = sfSprite_create();
    sfSprite_setTexture(play->map2_s, play->map2, sfTrue);
    play->map_b = sfTexture_createFromFile("res/map/milieu_obj.png", NULL);
    play->map_sb = sfSprite_create();
    sfSprite_setTexture(play->map_sb, play->map_b, sfTrue);
    play->map1_b = sfTexture_createFromFile("res/map/gauche_obj.png", NULL);
    play->map1_sb = sfSprite_create();
    sfSprite_setTexture(play->map1_sb, play->map1_b, sfTrue);
    play->map2_b = sfTexture_createFromFile("res/map/haut_obj.png", NULL);
    play->map2_sb = sfSprite_create();
    sfSprite_setTexture(play->map2_sb, play->map2_b, sfTrue);
}

static void fill_fight(play_t *play)
{
    const char *map = "res/map/map_combat.png";
    const char *mapb = "res/map/map_combat_obj.png";

    play->map_fight = sfTexture_createFromFile(map, NULL);
    play->map_fight_s = sfSprite_create();
    sfSprite_setTexture(play->map_fight_s, play->map_fight, sfTrue);
    play->map_fight_b = sfTexture_createFromFile(mapb, NULL);
    play->map_fight_sb = sfSprite_create();
    sfSprite_setTexture(play->map_fight_sb, play->map_fight_b, sfTrue);
}

void fill_struct_play(play_t *play)
{
    fill_map(play);
    fill_fight(play);
    fill_pos(play);
    play->change_m = 0;
    play->village = sfMusic_createFromFile("res/music/village.ogg");
}
