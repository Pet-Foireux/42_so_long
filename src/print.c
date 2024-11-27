/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:47:25 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/27 23:11:18 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	print(t_init *init, void *img, int x, int y)
{
	mlx_put_image_to_window(init->mlx, init->win, img,
		32 * x, 32 * y);
}

void	print_map(t_init *init, t_count *count, t_move *move)
{
	int	y;
	int	x;

	y = 0;
	while (y < init->height)
	{
		x = 0;
		while (x < init->widht)
		{
			if (init->map[y][x] == '1')
				print_wall(init, x, y);
			else if (init->map[y][x] == '0')
				print_floor(init, x, y);
			else if (init->map[y][x] == 'C')
				print_coin(init, count, x, y);
			else if (init->map[y][x] == 'E')
				print_exit(init, count, x, y);
			else if (init->map[y][x] == 'P')
				print_player(init, move, x, y);
			else
				other(init, x, y);
			x++;
		}
		y++;
	}
}

void	other(t_init *init, int x, int y)
{
	ft_printf("Error\nJ'accepete pas ce que tu me met en :");
	ft_printf("x = %d, y = %d.\n", x, y);
	ft_exit(init);
}
