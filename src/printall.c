/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:16:23 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/18 12:16:23 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_wall(t_init *init, int x, int y)
{
	print(init, init->wall_img, x, y);
}

void	print_floor(t_init *init, int x, int y)
{
	print(init, init->floor_img, x, y);
}

void	print_coin(t_init *init, t_count *count, int x, int y)
{
	print(init, init->coin_img, x, y);
	count->count_piece++;
}

void	print_exit(t_init *init, t_count *count, int x, int y)
{
	print(init, init->exit_img, x, y);
	count->count_exit++;
}

void	print_player(t_init *init, t_move *move, int x, int y)
{
	print(init, init->player_img, x, y);
	move->count_player++;
	move->player_x = x;
	move->player_y = y;
	move->new_x = move->player_x;
	move->new_y = move->player_y;
}
