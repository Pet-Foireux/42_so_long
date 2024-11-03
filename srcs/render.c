#include "so_long.h"

void render_map(t_vars *vars) 
{
    int x = 0;
    int y;
    vars->conteur_pieces = 0;

    while (x < vars->height) 
    {
        y = 0;
        while (y < vars->width) 
        {
            if (vars->map[x][y] == '1') 
                mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, y * 16, x * 16);
            else if (vars->map[x][y] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_img, y * 16, x * 16);
            else if (vars->map[x][y] == 'C')
            {
                vars->conteur_pieces++;
                mlx_put_image_to_window(vars->mlx, vars->win, vars->coin_img, y * 16, x * 16);
            }
            else if (vars->map[x][y] == 'E')
            {
                vars->sortit_x = x * 16;
                vars->sortit_y = y * 16;
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sortit_img, y * 16, x * 16);
            }
            y++;
        }
        x++;
    }
}

int render_next_frame(t_vars *vars) 
{
    int player_x_index = vars->player_x / 16;
    int player_y_index = vars->player_y / 16;

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
            ft_printf("Congratulations, you found all the coins and the exit.\n");
            ft_printf("Is %d moves really the best you can do ?\n", *vars->conteur);
            exit(0);
        }
    }
    else if (vars->conteur_pieces > 0 )
        mlx_put_image_to_window(vars->mlx, vars->win, vars->sortit_img, vars->sortit_y, vars->sortit_x);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_img, vars->last_x, vars->last_y);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player_img, vars->player_x, vars->player_y);
    return 0;
}