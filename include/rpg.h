/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** .h
*/

#ifndef _RPG_H_
#define _RPG_H_

/* CSFML LIBS */
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

/* TEXT */
#include "text.h"

/* STRUCTURES */
#include "struct.h"
int check_malloc(game_t *game);

void fill_struct(game_t *game);
void fill_struct_play(play_t *play);
void fill_save(game_t *game);
void fill_struct_mouse(cursor_t *cursor);
void fill_struct_quest(quest_t *quest, sfFont *font);
void fill_struct_hud(hud_t *hud, sfFont *font);
void fill_struct_fight(fight_t *fight);
void fill_pos_inv(inven_t *inven);
void event_close(game_t *game);
void display_cursor(game_t *game);

/* MAIN MENU */
void start_game(game_t *game);
void draw_main_menu(game_t *game);
void react_button_main(game_t *game);
void create_button_main(main_t *menu);
void create_text_main(main_t *menu);

/* HOW TO PLAY MENU */
void draw_how_to_play(game_t *game);
void react_button_htp(game_t *game);
void create_button_htp(htp_t *how, main_t *menu);
void create_text_htp(htp_t *how, main_t *menu);

/* CHOOSE YOUR CHARACTER */
void choose_player(game_t *game);
void draw_choose_png(game_t *game);
void create_sprites_choose(charac_t *chac);
void create_text_choose(game_t *game);
void create_button_choose(charac_t *chac);
void react_button_choose_c(game_t *game);
void react_button_choose_s(game_t *game);

/* GAME */
void display_game(game_t *game);
void draw_player(game_t *game);
void display_hud(hud_t *hud, sfRenderWindow *win);
void draw_map(game_t *game);

/* PAUSE */
void create_button_pause(game_t *game);
void create_text_pause(game_t *game);
void react_button_pause(game_t *game);
void draw_pause(game_t *game);

/* INVENTORY */
void display_inventory(game_t *game);
void interact_inv(inven_t *inven, game_t *game);

/* MOVEMENT */
void get_dir(game_t *game);
void move_up(game_t *game, play_t *play);
void move_down(game_t *game, play_t *play);
void move_right(game_t *game, play_t *play);
void move_left(game_t *game, play_t *play);
void change_map_left(play_t *play);
void change_map_down(play_t *play);
void change_map_up(play_t *play);
void change_map_right(play_t *play);

/* QUEST */
void draw_quest_bubble(int status, game_t *game);
void quest_handling(game_t *game);
void end_quest(quest_t *quest, game_t *game);
void battle_start(game_t *game);
int react_button_fight(fight_t *fight, game_t *game);
void display_end_fight(game_t *game, int win);
void game_over(game_t *game);

/* END OF GAME */
void my_destroy(game_t *game);
void destroy_play(game_t *game);
void destroy_inven_and_cursor(inven_t *inven, cursor_t *cursor);
void destroy_quest_and_hud(quest_t *quest, hud_t *hud);
void destroy_fight(fight_t *fight);

/* HELP AND ERROR */
int display_help(void);
int error_handling(int ac, char **av);
int error_handling_env(game_t *game, char **env);

/* UTIL FUNCTIONS */
void my_putchar(char c);
void my_putchar_error(char c);
void my_putstr(char *str);
void my_putstr_error(char *str);
void write_error(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);
char *my_revstr(char *str);
char *my_strcat(char const *str1, char const *str2);

/* COLISION */
int check_colision_x(play_t *play, int id);
int check_map_zero_r(sfVector2f pos);
int check_map_one_r(sfVector2f pos);
int check_map_two_r(sfVector2f pos);
int check_map_zero_lf(sfVector2f pos);
int check_map_one_lf(sfVector2f pos);
int check_map_two_lf(sfVector2f pos);
int check_colision_y(play_t *play, int id);
int check_map_zero_d(sfVector2f pos);
int check_map_one_d(sfVector2f pos);
int check_map_two_d(sfVector2f pos);
int check_map_zero_u(sfVector2f pos);
int check_map_one_u(sfVector2f pos);
int check_map_two_u(sfVector2f pos);

/* MACROS */
// RETURN VALUE //
static const int MAIN = 0;
static const int GAME = 1;
static const int END = 2;
static const int PAUSE = 3;
static const int MENU = 4;
static const int HTP = 5;

// RETURN FUNCTION //
static const int TRUE = 1;
static const int FALSE = 0;
static const int SUCCESS = 0;
static const int ERROR = 84;

// ERROR MESSAGE //
static const char STR_ERROR_ARG[] = "this program needs no arg (see with -h)\n";

#endif /* _RPG_H_ */
