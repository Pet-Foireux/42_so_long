/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:58:03 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/24 11:18:32 by mpapin           ###   ########.fr       */
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
	if (init->visited != NULL)
	{
		i = 0;
		while (init->visited[i] != NULL)
		{
			free(init->visited[i]);
			i++;
		}
		free(init->visited);
		init->visited = NULL;
	}
}

int	ft_exit(t_init *init)
{
	if (init->win)
		mlx_destroy_window(init->mlx, init->win);
	if (init->coin_img)
		mlx_destroy_image(init->mlx, init->coin_img);
	if (init->wall_img)
		mlx_destroy_image(init->mlx, init->wall_img);
	if (init->floor_img)
		mlx_destroy_image(init->mlx, init->floor_img);
	if (init->player_img)
		mlx_destroy_image(init->mlx, init->player_img);
	if (init->exit_img)
		mlx_destroy_image(init->mlx, init->exit_img);
	free_map(init);
	if (init->mlx)
	{
		mlx_destroy_display(init->mlx);
		free(init->mlx);
	}
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_init	init;
	t_count	count;
	t_move	move;

	move.mouvements = 0;
	move.init = &init;
	move.count = &count;
	init_count_move(&init, &count, &move);
	check_args(argc, argv);
	parse_map(&init, argv);
	check_all(&init);
	init_xpm(&init);
	print_map(&init, &count, &move);
	check_count(&init, &count, &move);
	check_chemin(&init, &move, &count);
	mlx_key_hook(init.win, handle_key, &move);
	mlx_hook(init.win, 17, 1L << 17, exit_croix, &init);
	mlx_loop(init.mlx);
}
