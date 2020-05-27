/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** end of the quest
*/

#include "rpg.h"

static int react_button_quest(quest_t *quest, game_t *game)
{
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    sfRectangleShape_setOutlineColor(quest->but, sfBlack);
    if (game->mouse.x >= 765 && game->mouse.x <= 1075)
        if (game->mouse.y >= 665 && game->mouse.y <= 775) {
            sfRectangleShape_setOutlineColor(quest->but, sfWhite);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (TRUE);
        }
    return (FALSE);
}

static void draw_button_and_text(quest_t *quest, sfRenderWindow *win)
{
    sfText_setString(quest->resp, "Thanks !");
    sfText_setPosition(quest->resp, (sfVector2f) {800, 670});
    sfRenderWindow_drawText(win, quest->resp, NULL);
    sfRectangleShape_setSize(quest->but, (sfVector2f) {300, 100});
    sfRectangleShape_setPosition(quest->but, (sfVector2f) {770, 670});
    sfRenderWindow_drawRectangleShape(win, quest->but, NULL);
}

static void increase_stat(game_t *game)
{
    game->quest->status = 3;
    game->hud->stat[2] += 10;
    game->hud->stat[2] %= game->hud->stat[5];
    game->hud->stat[1] += 1;
    game->hud->stat[3] += 2;
    game->hud->stat[4] += 3;
    game->quest->claim = 1;
    if (game->chara == 1 || game->chara == 4)
        game->hud->stat[0] = 50;
    else
        game->hud->stat[0] = 35;
}

void end_quest(quest_t *quest, game_t *game)
{
    const char *str = "res/quest/farmer_quest_end.png";

    quest->text = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(quest->text_s, quest->text, sfTrue);
    if (sfKeyboard_isKeyPressed(sfKeyT)) {
        while (sfRenderWindow_isOpen(game->win)) {
            event_close(game);
            draw_player(game);
            sfRenderWindow_drawSprite(game->win, quest->text_s, NULL);
            draw_button_and_text(game->quest, game->win);
            if (react_button_quest(game->quest, game))
                break;
            display_cursor(game);
            sfRenderWindow_display(game->win);
        }
        increase_stat(game);
    }
}
