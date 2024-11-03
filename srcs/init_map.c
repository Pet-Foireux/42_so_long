#include "so_long.h"

void position_player(t_vars *vars) 
{
    int i = 0;
    int j;

    while (i < vars->height) 
    {
        j = 0;
        while (j < vars->width) 
        {
            if (vars->map[i][j] == 'P') 
            {
                vars->player_x = j * 16;
                vars->player_y = i * 16;
                vars->last_x = vars->player_x;
                vars->last_y = vars->player_y;
                return;
            }
            j++;
        }
        i++;
    }
}

void check_borders(t_vars *vars) 
{
    int i;

    i = 0;
    while (i < vars->width) 
    {
        if (vars->map[0][i] != '1' || vars->map[vars->height - 1][i] != '1')
        {
            printf("La map est pas fermer chef\n");
            ft_exit_succes(vars);
        }
        i++;
    }

    i = 0;
    while (i < vars->height) 
    {
        if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
        {
            printf("La map est pas fermer chef\n");
            ft_exit_succes(vars);
        }
        i++;
    }
}

void init_window(t_vars *vars) 
{
    int width, height;

    vars->player_speed = 16;

    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, vars->width * 16, vars->height * 16, "Jeu");
    vars->player_img = mlx_xpm_file_to_image(vars->mlx, "img/player.xpm", &width, &height);
    vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "img/wall.xpm", &width, &height);
    vars->floor_img = mlx_xpm_file_to_image(vars->mlx, "img/floor.xpm", &width, &height);
    vars->coin_img = mlx_xpm_file_to_image(vars->mlx, "img/collectible.xpm", &width, &height);
    vars->sortit_img = mlx_xpm_file_to_image(vars->mlx, "img/sortit.xpm", &width, &height);

    if (vars->player_img == NULL || vars->wall_img == NULL || vars->floor_img == NULL) 
        exit(EXIT_FAILURE);
}
