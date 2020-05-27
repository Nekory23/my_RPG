/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fill the game structures
*/

#include "rpg.h"

static void fill_struct_inv(inven_t *inven)
{
    inven->inv = sfTexture_createFromFile("res/pics/inv.png", NULL);
    inven->inv_s = sfSprite_create();
    sfSprite_setTexture(inven->inv_s, inven->inv, sfTrue);
    sfSprite_setPosition(inven->inv_s, (sfVector2f) {240, 100});
    fill_pos_inv(inven);
}

static void fill_struct_choose(charac_t *chac)
{
    chac->type = sfTexture_createFromFile("res/char/face.png", NULL);
    chac->type_s = sfSprite_create();
    chac->rect_s.width = 300;
    chac->rect_s.height = 500;
    chac->rect_s.top = 500;
    sfSprite_setTexture(chac->type_s, chac->type, sfTrue);
    chac->type_s1 = sfSprite_copy(chac->type_s);
    chac->type_s2 = sfSprite_copy(chac->type_s);
    sfSprite_setTextureRect(chac->type_s, chac->rect_s);
    sfSprite_setPosition(chac->type_s, (sfVector2f) {140, 400});
    chac->rect_s.left = 300;
    sfSprite_setTextureRect(chac->type_s1, chac->rect_s);
    sfSprite_setPosition(chac->type_s1, (sfVector2f) {780, 400});
    chac->rect_s.left += 300;
    sfSprite_setTextureRect(chac->type_s2, chac->rect_s);
    sfSprite_setPosition(chac->type_s2, (sfVector2f) {1420, 400});
    create_sprites_choose(chac);
    create_button_choose(chac);
}

static void fill_struct_menu(main_t *menu)
{
    menu->bgd = sfTexture_createFromFile("res/pics/bckg.jpg", NULL);
    menu->bgd_s = sfSprite_create();
    sfSprite_setTexture(menu->bgd_s, menu->bgd, sfTrue);
    menu->music = sfMusic_createFromFile("res/music/main.ogg");
    create_text_main(menu);
    create_button_main(menu);
}

static void fill_struct_how(htp_t *how, main_t *menu)
{
    how->scroll = sfTexture_createFromFile("res/pics/scroll.png", NULL);
    how->scroll_s = sfSprite_create();
    sfSprite_setTexture(how->scroll_s, how->scroll, sfTrue);
    how->pos_sp.x = 600;
    how->pos_sp.y = 75;
    sfSprite_setPosition(how->scroll_s, how->pos_sp);
    create_text_htp(how, menu);
    create_button_htp(how, menu);
}

void fill_struct(game_t *game)
{
    sfVideoMode vm = {1920, 1080, 32};

    game->status = 0;
    game->ret = MAIN;
    game->clock = sfClock_create();
    game->menu->text_c = sfColor_fromRGB(139, 69, 19);
    game->menu->box_c = sfColor_fromRGB(56, 28, 0);
    game->chac->color = sfColor_fromRGB(187, 11, 11);
    game->win = sfRenderWindow_create(vm, RPG, sfResize | sfClose, NULL);
    fill_struct_menu(game->menu);
    fill_struct_how(game->how, game->menu);
    create_text_pause(game);
    create_button_pause(game);
    fill_struct_choose(game->chac);
    fill_struct_play(game->play);
    create_text_choose(game);
    fill_struct_inv(game->inven);
    fill_struct_mouse(game->cursor);
    fill_struct_quest(game->quest, game->menu->font);
    fill_struct_hud(game->hud, game->menu->font);
    fill_struct_fight(game->fight);
}
