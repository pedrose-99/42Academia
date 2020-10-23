#include "cub3d.h"

void    init_game(t_config *game, int save_game)
{
    int     i;

    init_conf(&game->conf);
    set_pos(&game->move, 0, 0);
    set_pos(&game->x_move, 0, 0);
    set_pos(&game->rotate, 0, 0);
    game->collected = 0;
    game->options = 0x11111110;
}

void    init_conf(t_config *game, int save_game)
{
    int i;

    
}
void    init_game(t_config *game, int save_opt)
{
    init i;

    init_config(&game->config);
    set_pos(&game->move, 0, 0);
    set_pos(&game->x_move, 0, 0);
    set_pos(&game->rotate_speed, 0 ,0);
    game->collected = 0;
    game->options = ;
    game->sprites = NULL;
    if (i < TEXTURES)
    {
        game->tex[i]-tex = NULL;
        i++;
    }
}
void    finish_init(t_config *game)
{
    if (!init_window(&game->window, &game->config))
    {
        return(exit_error(game,"Error: nmlx failed to create window or image,\n"));
    }
    find_start_pos();
    find_start_angle();
    if (!find_sprites(game))
        return(exit_error(game, "Error: nfailed to malloc sprites.\n "));
    if (!load_textures(game))
        return(exit_error(game, "Error:failed to load textures.\n"));
    return(1);
}
int    exit_game(t_config *game, int code)
{
    clear_config(&game->config);
    clear_window(&game)->window;
    clear_sprites(&game->sprites);
    exit(code);
    return(code);
}
int clear_config(t_config *config)
{
    int i;

    i = 0;
    while (i < TEXTURES)
    {
        if (config->tex_path[i])
            free(config->tex_path[i]);
            i++;
    }
    if (config->map)
        free(config->map);
    config->map = NULL;
    return (0);
}
