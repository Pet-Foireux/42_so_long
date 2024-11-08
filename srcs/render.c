/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:12:05 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/08 12:38:29 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_vars *vars)
{
	vars->conteur_pieces = 0;
	vars->x = 0;
	while (vars->x < vars->height)
	{
		vars->y = 0;
		while (vars->y < vars->width)
		{
			if (vars->map[vars->x][vars->y] == '1')
				print_img(vars, vars->wall_img, vars->y, vars->x);
			else if (vars->map[vars->x][vars->y] == '0')
				print_img(vars, vars->floor_img, vars->y, vars->x);
			else if (vars->map[vars->x][vars->y] == 'C')
			{
				vars->conteur_pieces++;
				print_img(vars, vars->coin_img, vars->y, vars->x);
			}
			else if (vars->map[vars->x][vars->y] == 'E')
				init_e(vars);
			vars->y++;
		}
		vars->x++;
	}
}

int	render_next_frame(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x] == 'C')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->conteur_pieces--;
	}
	if (vars->map[vars->player_y][vars->player_x] == 'E'
		&& vars->conteur_pieces == 0)
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		printf("Congratulations, you found all the coins and the exit.\n");
		exit(0);
	}
	else if (vars->conteur_pieces > 0)
		print_img(vars, vars->sortit_img, vars->sortit_y, vars->sortit_x);
	print_img(vars, vars->floor_img, vars->last_x, vars->last_y);
	print_img(vars, vars->player_img, vars->player_x, vars->player_y);
	return (0);
}
