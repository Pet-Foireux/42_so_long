/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:47:25 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/18 11:37:39 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	print(t_init *init, void *img, int x, int y)
{
	mlx_put_image_to_window(init->mlx, init->win, img,
		32 * x, 32 * y);
}

void	print_map(t_init *init, t_count *count)
{
	int	y;
	int	x;

	count->count_exit = 0;
	count->count_piece = 0;
	count->count_player = 0;
	y = 0;
	while (y < init->height)
	{
		x = 0;
		while (x < init->widht)
		{
			if (init->map[y][x] == '1')
				print(init, init->wall_img, x, y);
			else if (init->map[y][x] == '0')
				print(init, init->floor_img, x, y);
			else if (init->map[y][x] == 'C')
			{
				print(init, init->coin_img, x, y);
				count->count_piece++;
			}
			else if (init->map[y][x] == 'E')
			{
				print(init, init->exit_img, x, y);
				count->count_exit++;
			}
			else if (init->map[y][x] == 'P')
			{
				print(init, init->player_img, x, y);
				count->count_player++;
			}
			x++;
		}
		y++;
	}
}
