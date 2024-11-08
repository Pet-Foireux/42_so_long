/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:11:59 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/08 13:54:37 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_lettre(t_vars *vars)
{
	if (vars->conteur_p != 1)
	{
		ft_printf("Something wrong with the numbers of starting position.\n");
		ft_exit_fail(vars);
	}
	else if (vars->conteur_e != 1)
	{
		ft_printf("Something wrong with the numbers of exit.\n");
		ft_exit_fail(vars);
	}
}

void	init_e(t_vars *vars)
{
	vars->conteur_e++;
	vars->sortit_x = vars->x;
	vars->sortit_y = vars->y;
	print_img(vars, vars->sortit_img, vars->sortit_y, vars->sortit_x);
}

void	print_img(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		32 * x, 32 * y);
}
