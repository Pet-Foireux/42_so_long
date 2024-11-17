/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:30:25 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/17 08:44:00 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_xpm(t_init *init)
{
	int	widht;
	int	height;

	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, init->widht * 32,
			init->height * 32, "so_long");
	init->coin_img = mlx_xpm_file_to_image(init->mlx, "besoin/struct/coin.xpm",
			&widht, &height);
	init->exit_img = mlx_xpm_file_to_image(init->mlx, "besoin/struct/exit.xpm",
			&widht, &height);
	init->floor_img = mlx_xpm_file_to_image(init->mlx,
			"besoin/struct/floor.xpm", &widht, &height);
	init->wall_img = mlx_xpm_file_to_image(init->mlx, "besoin/struct/wall.xpm",
			&widht, &height);
	init->player_img = mlx_xpm_file_to_image(init->mlx,
			"besoin/struct/player.xpm", &widht, &height);
}
