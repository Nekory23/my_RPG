/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** error_handling
*/

#include "rpg.h"

static int check_env(char **env)
{
    int check = 0;

    for (int i = 0; env[i] != NULL; i++)
        if (my_strcmp(env[i], "DISPLAY=:0.0"))
            check = 1;
    if (check == 1)
        return (SUCCESS);
    else
        return (ERROR);
}

int error_handling_env(game_t *game, char **env)
{
    int error_env = check_env(env);

    if (error_env == ERROR) {
        my_putstr_error("ERROR : Display Environnement ");
        my_putstr_error("doesn't exist or is null\n");
        return (TRUE);
    }
    if (game == NULL || check_malloc(game)) {
        my_putstr_error("ERROR : Memory allocation failed\n");
        return (TRUE);
    }
    return (FALSE);
}

int error_handling(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h"))
        return (display_help());
    if (ac != 1) {
        write_error(STR_ERROR_ARG);
        return (ERROR);
    }
    return (TRUE);
}
