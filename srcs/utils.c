#include "so_long.h"

void    check_lettre(t_vars *vars)
{
    if (vars->conteur_p > 1 || vars->conteur_p == 0)
        {
            printf("Something wrong with the numbers of starting position.\n");
            ft_exit_fail(vars);
        }
    else if (vars->conteur_e > 1 || vars->conteur_e == 0)
        {
            printf("Something wrong with the numbers of exit.\n");
            ft_exit_fail(vars);
        }
}

void init_e(t_vars *vars)
{
    vars->conteur_e++;
    vars->sortit_x = vars->x * 32;
    vars->sortit_y = vars->y * 32;
    mlx_put_image_to_window(vars->mlx, vars->win, vars->sortit_img, vars->y * 32, vars->x * 32);
}
