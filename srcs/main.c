#include "so_long.h"

void init_map(t_vars *vars, char **initial_map) 
{
    vars->height = 0;
    while (initial_map[vars->height])
        vars->height++;
    
    vars->width = strlen(initial_map[0]);
    vars->map = malloc(vars->height * sizeof(char *));
    if (!vars->map) 
    {
        printf("Failed to allocate memory for the map");
        ft_exit_fail(vars);
    }

    int i = 0;
    while (i < vars->height) 
    {
        vars->map[i] = strdup(initial_map[i]);
        if (!vars->map[i]) 
        {
            printf("Failed to duplicate map row");
            ft_exit_fail(vars);
        }
        i++;
    }
}

void free_map(t_vars *vars) 
{
    int i = 0;
    while (i < vars->height) 
    {
        free(vars->map[i]);
        i++;
    }
    free(vars->map);
}

void ft_exit_fail(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_window(vars->mlx, vars->win);
    free_map(vars);
    exit(EXIT_FAILURE);
}

void ft_exit_succes(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_window(vars->mlx, vars->win);
    free_map(vars);
    exit(EXIT_SUCCESS);
}

int main(void) 
{
    t_vars vars;
    int conteur = 0;

    char *initial_map[] = {
    "1111111111111111111111111",
    "1000000001C00101000001011",
    "1010011101010101010101011",
    "1010011101010101010101011",
    "1P0000110000000001E000011",
    "1111111111111111111111111",
    NULL
    };
    vars.conteur = &conteur;
    init_map(&vars, initial_map);
    position_player(&vars);
    init_window(&vars);
    render_map(&vars);
    check_lettre(&vars);
    check_borders(&vars);
    mlx_key_hook(vars.win, handle_key, &vars);
    mlx_loop_hook(vars.mlx, render_next_frame, &vars);
    mlx_loop(vars.mlx);
    free_map(&vars);
    return 0;
}
