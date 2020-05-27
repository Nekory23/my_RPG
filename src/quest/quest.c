/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** handles the quest
*/

#include "rpg.h"

static void draw_buttons(quest_t *quest, sfRenderWindow *win)
{
    sfRectangleShape_setPosition(quest->but, (sfVector2f) {580, 700});
    sfText_setPosition(quest->resp, (sfVector2f) {620, 700});
    quest->size_b.x = 270;
    quest->size_b.y = 100;
    sfRectangleShape_setSize(quest->but, quest->size_b);
    sfText_setString(quest->resp, "Accept");
    sfRenderWindow_drawText(win, quest->resp, NULL);
    sfRenderWindow_drawRectangleShape(win, quest->but, NULL);
    sfRectangleShape_setPosition(quest->but2, (sfVector2f) {1080, 700});
    sfRectangleShape_setSize(quest->but2, quest->size_b);
    sfText_setString(quest->resp, "Deny");
    sfText_setPosition(quest->resp, (sfVector2f) {1150, 700});
    sfRenderWindow_drawText(win, quest->resp, NULL);
    sfRenderWindow_drawRectangleShape(win, quest->but2, NULL);
}

static int react_button_quest(quest_t *quest, game_t *game)
{
    sfRectangleShape_setOutlineColor(quest->but, sfBlack);
    sfRectangleShape_setOutlineColor(quest->but2, sfBlack);
    game->mouse = sfMouse_getPositionRenderWindow(game->win);
    if (game->mouse.x >= 575 && game->mouse.x <= 855)
        if (game->mouse.y >= 695 && game->mouse.y <= 805) {
            sfRectangleShape_setOutlineColor(quest->but, sfWhite);
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                quest->status = 1;
                return (TRUE);
            }
        }
    if (game->mouse.x >= 1075 && game->mouse.x <= 1345)
        if (game->mouse.y >= 695 && game->mouse.y <= 805) {
            sfRectangleShape_setOutlineColor(quest->but2, sfWhite);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                return (TRUE);
        }
    return (FALSE);
}

static void talk_to_pnj(quest_t *quest, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyT)) {
        while (sfRenderWindow_isOpen(game->win)) {
            event_close(game);
            draw_player(game);
            sfRenderWindow_drawSprite(game->win, quest->text_s, NULL);
            draw_buttons(game->quest, game->win);
            if (react_button_quest(game->quest, game))
                break;
            display_cursor(game);
            sfRenderWindow_display(game->win);
        }
    }
}

void quest_handling(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->play->player_s);

    if (game->play->change_m == 0 && game->quest->status == 0)
        if ((pos.x >= 1600) && (pos.y >= 445 && pos.y <= 555))
            talk_to_pnj(game->quest, game);
    if (game->play->change_m == 0 && game->quest->kill == 1)
        if (game->quest->claim == 0)
            if ((pos.x >= 1600) && (pos.y >= 445 && pos.y <= 555))
                end_quest(game->quest, game);
}
