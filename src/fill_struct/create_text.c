/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create the text
*/

#include "rpg.h"
#include "text.h"

void create_text_main(main_t *menu)
{
    menu->font = sfFont_createFromFile("res/fonts/main_font.TTF");
    menu->text = sfText_create();
    sfText_setString(menu->text, "My_RPG");
    sfText_setCharacterSize(menu->text, 200);
    sfText_setPosition(menu->text, (sfVector2f) {1100, 30});
    sfText_setColor(menu->text, menu->text_c);
    sfText_setFont(menu->text, menu->font);
    menu->play = sfText_copy(menu->text);
    sfText_setString(menu->play, "Play");
    sfText_setCharacterSize(menu->play, 100);
    sfText_setPosition(menu->play, (sfVector2f) {1100, 250});
    menu->quit = sfText_copy(menu->text);
    sfText_setString(menu->quit, "Quit");
    sfText_setCharacterSize(menu->quit, 100);
    sfText_setPosition(menu->quit, (sfVector2f) {1500, 250});
    menu->htp = sfText_copy(menu->text);
    sfText_setString(menu->htp, "How to play");
    sfText_setCharacterSize(menu->htp, 100);
    sfText_setPosition(menu->htp, (sfVector2f) {1200, 400});
}

void create_text_htp(htp_t *how, main_t *menu)
{
    how->text = sfText_create();
    sfText_setString(how->text, "How to play");
    sfText_setCharacterSize(how->text, 100);
    sfText_setPosition(how->text, (sfVector2f) {760, 180});
    sfText_setColor(how->text, menu->text_c);
    sfText_setFont(how->text, menu->font);
    how->ret = sfText_copy(how->text);
    sfText_setString(how->ret, "Return");
    sfText_setCharacterSize(how->ret, 75);
    sfText_setPosition(how->ret, (sfVector2f) {860, 725});
    how->htp = sfText_copy(how->text);
    sfText_setString(how->htp, STR_HTP);
    sfText_setPosition(how->htp, (sfVector2f) {680, 300});
    sfText_setCharacterSize(how->htp, 50);
    sfText_setColor(how->htp, sfBlack);
}

void create_text_pause(game_t *game)
{
    game->pause->pause_t = sfText_create();
    sfText_setString(game->pause->pause_t, "Paused");
    sfText_setCharacterSize(game->pause->pause_t, 100);
    sfText_setPosition(game->pause->pause_t, (sfVector2f) {840, 180});
    sfText_setColor(game->pause->pause_t, game->menu->text_c);
    sfText_setFont(game->pause->pause_t, game->menu->font);
    game->pause->resume = sfText_copy(game->pause->pause_t);
    sfText_setString(game->pause->resume, "Resume");
    sfText_setPosition(game->pause->resume, (sfVector2f) {750, 350});
    sfText_setCharacterSize(game->pause->resume, 75);
    game->pause->quit = sfText_copy(game->pause->resume);
    sfText_setString(game->pause->quit, "Quit game");
    sfText_setPosition(game->pause->quit, (sfVector2f) {750, 550});
    game->pause->main = sfText_copy(game->pause->resume);
    sfText_setString(game->pause->main, "Main menu");
    sfText_setPosition(game->pause->main, (sfVector2f) {750, 450});
}

void create_text_choose(game_t *game)
{
    game->chac->choose = sfText_create();
    sfText_setString(game->chac->choose, "Choose your character");
    sfText_setCharacterSize(game->chac->choose, 200);
    sfText_setPosition(game->chac->choose, (sfVector2f) {330, 50});
    sfText_setColor(game->chac->choose, game->menu->text_c);
    sfText_setFont(game->chac->choose, game->menu->font);
    game->chac->caract = sfText_copy(game->chac->choose);
    sfText_setCharacterSize(game->chac->caract, 50);
    sfText_setColor(game->chac->caract, sfWhite);
}
