/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:12:13 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/08 12:38:33 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x;
	new_y = vars->player_y;
	if (key == 'd')
		new_x += vars->player_speed;
	else if (key == 'a')
		new_x -= vars->player_speed;
	else if (key == 'w')
		new_y -= vars->player_speed;
	else if (key == 's')
		new_y += vars->player_speed;
	else if (key == 65307)
		handle_exit(vars);
	if (key == 'd' || key == 'a' || key == 'w' || key == 's')
	{
		(*vars->conteur)++;
		printf("You moved %d times.\n", *vars->conteur);
	}
	if (can_move_to(vars, new_x, new_y))
		update_player_position(vars, new_x, new_y);
	return (0);
}

void	handle_exit(t_vars *vars)
{
	printf("To hard for you ?\n");
	ft_exit_fail(vars);
}

int	can_move_to(t_vars *vars, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= vars->width || new_y < 0 || new_y >= vars->height)
		return (0);
	return (vars->map[new_y][new_x] != '1');
}

void	update_player_position(t_vars *vars, int new_x, int new_y)
{
	vars->last_x = vars->player_x;
	vars->last_y = vars->player_y;
	vars->player_x = new_x;
	vars->player_y = new_y;
}
