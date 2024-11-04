#include "so_long.h"

int handle_key(int key, t_vars *vars) 
{
    int new_x = vars->player_x;
    int new_y = vars->player_y;

    if (key == 'd')
    {
        (*vars->conteur)++;
        new_x += vars->player_speed;
        printf("You moved %d times.\n", *vars->conteur);
    }
    else if (key == 'a')
    {
        (*vars->conteur)++;
        new_x -= vars->player_speed;
        printf("You moved %d times.\n", *vars->conteur);
    }
    else if (key == 'w')
    { 
        (*vars->conteur)++;
        new_y -= vars->player_speed;
        printf("You moved %d times.\n", *vars->conteur);
    }
    else if (key == 's')
    {
        (*vars->conteur)++;
        new_y += vars->player_speed;
        printf("You moved %d times.\n", *vars->conteur);
    }
    else if (key == 65307)
    {
        printf("To hard for you ?\n");
        ft_exit_fail(vars);
    }
    if (can_move_to(vars, new_x, new_y))
        update_player_position(vars, new_x, new_y);
    return 0;
}

int can_move_to(t_vars *vars, int new_x, int new_y) 
{
    int map_x = new_x / 32;
    int map_y = new_y / 32;

    if (map_x < 0 || map_x >= vars->width || map_y < 0 || map_y >= vars->height)
        return 0;
    return (vars->map[map_y][map_x] != '1');
}

void update_player_position(t_vars *vars, int new_x, int new_y) 
{
    vars->last_x = vars->player_x;
    vars->last_y = vars->player_y;
    vars->player_x = new_x;
    vars->player_y = new_y;
}
