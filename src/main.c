/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include "rpg.h"

static int check_malloc_bis(game_t *game)
{
    game->fight = malloc(sizeof(fight_t));
    if (game->fight == NULL)
        return (TRUE);
    return (FALSE);
}

int check_malloc(game_t *game)
{
    game->how = malloc(sizeof(htp_t));
    game->menu = malloc(sizeof(main_t));
    game->cursor = malloc(sizeof(cursor_t));
    if (game->menu == NULL || game->how == NULL || game->cursor == NULL)
        return (TRUE);
    game->pause = malloc(sizeof(pause_t));
    game->play = malloc(sizeof(play_t));
    game->quest = malloc(sizeof(quest_t));
    if (game->play == NULL || game->pause == NULL || game->quest == NULL)
        return (TRUE);
    game->chac = malloc(sizeof(charac_t));
    game->inven = malloc(sizeof(inven_t));
    game->hud = malloc(sizeof(hud_t));
    if (game->chac == NULL || game->inven == NULL || game->hud == NULL)
        return (TRUE);
    return (check_malloc_bis(game));
}

static void free_struct(game_t *game)
{
    free(game->pause);
    free(game->how);
    free(game->menu);
    free(game->play);
    free(game->chac);
    free(game->inven);
    free(game->cursor);
    free(game->quest);
    free(game->hud);
    free(game->fight);
    free(game);
}

int main(int ac, char **av, char **env)
{
    int error = error_handling(ac, av);
    game_t *game = malloc(sizeof(game_t));

    if (error_handling_env(game, env))
        return (ERROR);
    if (error != TRUE)
        return (error);
    fill_save(game);
    start_game(game);
    while (game->ret == MAIN)
        start_game(game);
    sfTexture_destroy(game->play->player);
    sfSprite_destroy(game->play->player_s);
    free_struct(game);
    return (SUCCESS);
}
