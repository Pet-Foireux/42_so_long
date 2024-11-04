#include "so_long.h"

void position_player(t_vars *vars) 
{
    int i = 0;
    int j;
 
    vars->conteur_p = 0;
    while (i < vars->height) 
    {
        j = 0;
        while (j < vars->width) 
        {
            if (vars->map[i][j] == 'P') 
            {
                vars->conteur_p++;
                vars->player_x = j * 32;
                vars->player_y = i * 32;
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
            printf("Map not close.\n");
            ft_exit_succes(vars);
        }
        i++;
    }
    i = 0;
    while (i < vars->height) 
    {
        if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
        {
            printf("Map not close.\n");
            ft_exit_succes(vars);
        }
        i++;
    }
}

void init_window(t_vars *vars) 
{
    int width, height;
    vars->player_speed = 32;
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, vars->width * 32, vars->height * 32, "Jeu");
    vars->player_img = mlx_xpm_file_to_image(vars->mlx, "img/player.xpm", &width, &height);
    vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "img/wall.xpm", &width, &height);
    vars->floor_img = mlx_xpm_file_to_image(vars->mlx, "img/floor.xpm", &width, &height);
    vars->coin_img = mlx_xpm_file_to_image(vars->mlx, "img/collectible.xpm", &width, &height);
    vars->sortit_img = mlx_xpm_file_to_image(vars->mlx, "img/sortit.xpm", &width, &height);
    if (vars->player_img == NULL || vars->wall_img == NULL || vars->floor_img == NULL || vars->coin_img == NULL || vars->sortit_img == NULL) 
    {
        printf("Erreur: Une des images n'a pas pu être chargée.\n");
        exit(EXIT_FAILURE);
    }
}
