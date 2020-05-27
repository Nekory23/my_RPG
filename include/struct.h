/*
** EPITECH PROJECT, 2020
** rgp
** File description:
** struct.h
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

/* structure ecran titre */
typedef struct main_s
{
    sfTexture *bgd;
    sfSprite *bgd_s;
    sfText *text;
    sfText *play;
    sfText *quit;
    sfText *htp;
    sfFont *font;
    sfColor text_c;
    sfColor box_c;
    sfMusic *music;
    sfRectangleShape *but;
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *but2;
    sfVector2f pos2;
    sfRectangleShape *but3;
    sfVector2f pos3;
    sfVector2f size3;
} main_t;

/* structure how to play */
typedef struct htp_s
{
    sfTexture *scroll;
    sfSprite *scroll_s;
    sfText *text;
    sfText *htp;
    sfText *ret;
    sfRectangleShape *but;
    sfVector2f pos_sp;
    sfVector2f pos;
    sfVector2f size;
} htp_t;

/* structure menu pause */
typedef struct pause_s
{
    sfText *pause_t;
    sfText *resume;
    sfText *quit;
    sfText *main;
    sfRectangleShape *but;
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *but2;
    sfVector2f pos2;
    sfVector2f size2;
    sfRectangleShape *but3;
    sfVector2f pos3;
    sfVector2f size3;
} pause_t;

/* structure choix du perso */
typedef struct charac_s
{
    sfTexture *type;
    sfSprite *type_s;
    sfSprite *type_s1;
    sfSprite *type_s2;
    sfIntRect rect;
    sfIntRect rect_s;
    sfVector2f pos;
    sfTexture *but;
    sfSprite *but_s;
    sfRectangleShape *but1;
    sfVector2f pos1;
    sfVector2f size1;
    sfRectangleShape *but2;
    sfVector2f pos2;
    sfVector2f size2;
    sfRectangleShape *choice;
    sfVector2f pos_c;
    sfVector2f size_c;
    sfColor color;
    sfText *choose;
    sfText *type_t;
    sfText *caract;
} charac_t;

/* structure du jeu */
typedef struct play_s
{
    sfTexture *map;
    sfSprite *map_s;
    sfTexture *map_b;
    sfSprite *map_sb;
    sfVector2f posm;
    sfVector2f posmb;
    sfTexture *map1;
    sfSprite *map1_s;
    sfTexture *map1_b;
    sfSprite *map1_sb;
    sfVector2f posm1;
    sfTexture *map2;
    sfSprite *map2_s;
    sfTexture *map2_b;
    sfSprite *map2_sb;
    sfVector2f posm2;
    sfTexture *map_fight;
    sfSprite *map_fight_s;
    sfTexture *map_fight_b;
    sfSprite *map_fight_sb;
    sfVector2f posfight;
    sfMusic *village;
    sfTexture *player;
    sfSprite *player_s;
    sfIntRect rect;
    sfVector2f origin;
    sfVector2f pos;
    int change_m;
    int end_fight;
} play_t;

/* structure de l'inventaire */
typedef struct invent_s
{
    sfTexture *inv;
    sfSprite *inv_s;
    sfSprite *chara_s;
    sfIntRect inv_r;
    sfTexture *item;
    sfSprite *item_s;
    sfTexture *helmet;
    sfSprite *helmet_s;
    sfTexture *boot;
    sfSprite *boot_s;
    sfTexture *belt;
    sfSprite *belt_s;
    sfVector2f pos[6][4];
    sfVector2f pos_a[4];
    int slot[6][4];
    int armor[4];
} inven_t;

/* structure curseur */
typedef struct cursor_s
{
    sfRectangleShape *cursor_m;
    sfTexture *cursor;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f pos;
} cursor_t;

/* structure quete */
typedef struct quest_s
{
    sfTexture *pnj;
    sfSprite *pnj_s;
    sfTexture *text;
    sfSprite *text_s;
    sfRectangleShape *but;
    sfRectangleShape *but2;
    sfVector2f size_b;
    sfVector2f pos_b;
    sfText *resp;
    sfVector2f pos;
    sfTexture *bubble;
    sfSprite *bubble_s;
    sfIntRect rect_b;
    int status;
    int kill;
    int check;
    int claim;
} quest_t;

/* structure hud */
typedef struct hud_s
{
    sfRectangleShape *bkgd;
    sfText *pv;
    sfText *xp;
    sfText *level;
    sfText *def;
    sfText *att;
    sfText *stats;
    int stat[6];
} hud_t;

/* structure combat */
typedef struct fight_s
{
    int stats[3];
    int comp;
    sfMusic *battle;
    sfTexture *enemy;
    sfSprite *enemy_s;
    sfVector2f *pos_e;
    sfIntRect rect;
    sfRectangleShape *bkgd;
    sfRectangleShape *but1;
    sfRectangleShape *but2;
    sfText *text;
    sfSound *hurt;
    sfSound *death;
    sfSoundBuffer *buff1;
    sfSoundBuffer *buff2;
} fight_t;

/* structure principale */
typedef struct game_s
{
    int fight_i;
    int over;
    int ret;
    int chara;
    int status;
    sfClock *clock;
    sfTime time;
    sfRenderWindow *win;
    sfEvent event;
    sfVector2i mouse;
    main_t *menu;
    htp_t *how;
    pause_t *pause;
    charac_t *chac;
    play_t *play;
    inven_t *inven;
    cursor_t *cursor;
    quest_t *quest;
    hud_t *hud;
    fight_t *fight;
} game_t;

#endif // END _STRUCT_H_ //
