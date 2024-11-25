/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:57:59 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/25 23:02:26 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_key(int key, t_move *move)
{
	if (key == 'w')
		move->new_y -= 1;
	if (key == 's')
		move->new_y += 1;
	if (key == 'a')
		move->new_x -= 1;
	if (key == 'd')
		move->new_x += 1;
	if (key == 65307)
	{
		ft_printf("Trop dur le sang?\n");
		ft_exit(move->init);
	}
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		ft_mouvements(move);
	return (0);
}

int	ft_mouvements(t_move *move)
{
	if (can_move(move))
	{
		update(move);
	}
	else
	{
		move->new_x = move->player_x;
		move->new_y = move->player_y;
	}
	move->mouvements++;
	if (move->mouvements == 1)
		ft_printf("Tes as %d, deplacement.\n", move->mouvements);
	else
		ft_printf("Tes as %d, deplacements.\n", move->mouvements);
	return (0);
}

int	update(t_move *move)
{
	t_init	*init;

	init = move->init;
	move->last_x = move->player_x;
	move->last_y = move->player_y;
	move->player_x = move->new_x;
	move->player_y = move->new_y;
	print(move->init, init->player_img, move->player_x, move->player_y);
	print(move->init, init->floor_img, move->last_x, move->last_y);
	return (0);
}

int	can_move(t_move *move)
{
	if (move->init->map[move->new_y][move->new_x] == '1')
		return (0);
	if (move->init->map[move->new_y][move->new_x] == 'C')
	{
		move->init->map[move->new_y][move->new_x] = '0';
		move->count->count_piece--;
	}
	if (move->init->map[move->new_y][move->new_x] == 'E'
		&& move->count->count_piece != 0)
		return (0);
	if (move->init->map[move->new_y][move->new_x] == 'E'
		&& move->count->count_piece == 0)
	{
		ft_printf("Bravo a toi !\n");
		ft_printf("Finish avec %d mouvements, ", move->mouvements);
		ft_printf("peux-tu faire mieux ?\n");
		ft_exit(move->init);
	}
	return (1);
}

int	exit_croix(t_init *init)
{
	ft_printf("Trop dur le sang ?\n");
	ft_exit(init);
	return (0);
}
