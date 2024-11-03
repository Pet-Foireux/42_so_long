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
        ft_printf("Failed to allocate memory for the map");
        ft_exit_fail(vars);
    }

    int i = 0;
    while (i < vars->height) 
    {
        vars->map[i] = strdup(initial_map[i]);
        if (!vars->map[i]) 
        {
            ft_printf("Failed to duplicate map row");
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
    "1111111111111111111111111111111111",
    "1E00000000000000000000000000000001",
    "1C10010100100000101001000000010101",
    "1010010010101010001001000000010101",
    "1P00000000000000000000000000000001",
    "1111111111111111111111111111111111",
    NULL
    };
    vars.conteur = &conteur;
    init_map(&vars, initial_map);
    position_player(&vars);
    init_window(&vars);
    render_map(&vars);
    check_borders(&vars);
    mlx_key_hook(vars.win, handle_key, &vars);
    mlx_loop_hook(vars.mlx, render_next_frame, &vars);
    mlx_loop(vars.mlx);
    free_map(&vars);
    return 0;
}
