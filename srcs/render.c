#include "so_long.h"

void render_map(t_vars *vars) 
{
    vars->conteur_pieces = 0;
    vars->x = 0;
    while (vars->x < vars->height) 
    {
        vars->y = 0;
        while (vars->y < vars->width) 
        {
            if (vars->map[vars->x][vars->y] == '1') 
                mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, vars->y * 32, vars->x * 32);
            else if (vars->map[vars->x][vars->y] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_img, vars->y * 32, vars->x * 32);
            else if (vars->map[vars->x][vars->y] == 'C')
            {
                vars->conteur_pieces++;
                mlx_put_image_to_window(vars->mlx, vars->win, vars->coin_img, vars->y * 32, vars->x * 32);
            }
            else if (vars->map[vars->x][vars->y] == 'E')
                init_e(vars);
            vars->y++;
        }
        vars->x++;
    }
}

int render_next_frame(t_vars *vars) 
{
    int player_x_index = vars->player_x / 32;
    int player_y_index = vars->player_y / 32;

    if (vars->map[player_y_index][player_x_index] == 'C') 
    {
        vars->map[player_y_index][player_x_index] = '0';
        vars->conteur_pieces--;
    }
    if (vars->map[player_y_index][player_x_index] == 'E')
    {
        if (vars->conteur_pieces == 0)
        {
            vars->map[player_y_index][player_x_index] = '0';
            printf("Congratulations, you found all the coins and the exit.\n");
            printf("Is %d moves really the best you can do ?\n", *vars->conteur);
            exit(0);
        }
    }
    else if (vars->conteur_pieces > 0 )
        mlx_put_image_to_window(vars->mlx, vars->win, vars->sortit_img, vars->sortit_y, vars->sortit_x);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_img, vars->last_x, vars->last_y);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player_img, vars->player_x, vars->player_y);
    return 0;
}