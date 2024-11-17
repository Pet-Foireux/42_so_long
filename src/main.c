/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:58:03 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/17 07:02:19 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_init *init)
{
	int	i;

	if (init->map != NULL)
	{
		i = 0;
		while (init->map[i] != NULL)
		{
			free(init->map[i]);
			i++;
		}
		free(init->map);
		init->map = NULL;
	}
}

int	ft_exit(t_init *init)
{
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_image(init->mlx, init->coin_img);
	mlx_destroy_image(init->mlx, init->wall_img);
	mlx_destroy_image(init->mlx, init->floor_img);
	mlx_destroy_image(init->mlx, init->player_img);
	mlx_destroy_image(init->mlx, init->exit_img);
	free_map(init);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_init	init;

	init.widht = 0;
	init.height = 0;
	check_args(argc, argv);
	parse_map(&init, argv);
	init_xpm(&init);
	print_map(&init);
	mlx_hook(init.win, 17, 1L << 17, ft_exit, &init);
	mlx_loop(init.mlx);
}
