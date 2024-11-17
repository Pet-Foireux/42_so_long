/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:30:12 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/17 09:38:49 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int handle_key(int key, t_move *move, t_init *init)
{
    int	new_x;
	int	new_y;

	new_x = move->player_x;
	new_y = move->player_y;
	if (key == 'd')
		new_x += 32;
	else if (key == 'a')
		new_x -= 32;
	else if (key == 'w')
		new_y -= 32;
	else if (key == 's')
		new_y += 32;
	else if (key == 65307)
		handle_exit(init);
	if (key == 'd' || key == 'a' || key == 'w' || key == 's')
	{
		move->conteur++;
		ft_printf("T'a bouger %d fois.\n", move->conteur);
	}
	if (can_move_to(move, new_x, new_y))
		update_player_position(move, new_x, new_y);
	return (0);
}

void	handle_exit(t_init *init)
{
	ft_printf("Trop dur le sang ?\n");
	ft_exit(init);
}

int	can_move_to(t_init *init, t_count *count, new_x, int new_y)
{
	if (new_x < 0 || new_x >= init->width || new_y < 0 || new_y >= init->height)
		return (0);
	else if (count->count_piece != 0)
		return (init->map[new_y][new_x] != '1' &&
			(init->map[new_y][new_x] !=
			init->map[vars->sortit_y][vars->sortit_x]));
	else if (vars->conteur_pieces == 0)
		return (vars->map[new_y][new_x] != '1');
	return (0);
}

void	update_player_position(t_vars *vars, int new_x, int new_y)
{
	vars->last_x = vars->player_x;
	vars->last_y = vars->player_y;
	vars->player_x = new_x;
	vars->player_y = new_y;
}