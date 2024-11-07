/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:56:47 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/07 09:56:47 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_vars *vars, char **initial_map)
{
	int	i;

	i = 0;
	vars->height = 0;
	while (initial_map[vars->height])
		vars->height++;
	vars->width = strlen(initial_map[0]);
	vars->map = malloc(vars->height * sizeof(char *));
	if (!vars->map)
	{
		printf("Failed to allocate memory for the map");
		ft_exit_fail(vars);
	}
	while (i < vars->height)
	{
		vars->map[i] = strdup(initial_map[i]);
		if (!vars->map[i])
		{
			printf("Failed to duplicate map row");
			ft_exit_fail(vars);
		}
		i++;
	}
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	ft_exit_fail(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	free_map(vars);
	exit(EXIT_FAILURE);
}

void	ft_exit_succes(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	free_map(vars);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	static char	*initial_map[] = {
		"1111111",
		"1E00001",
		"1C10011",
		"1010011",
		"1P00001",
		"1111111",
		NULL
	};
	t_vars		vars;
	int			conteur;

	conteur = 0;
	vars.conteur = &conteur;
	init_map(&vars, initial_map);
	position_player(&vars);
	init_window(&vars);
	render_map(&vars);
	check_borders(&vars);
	mlx_key_hook(vars.win, handle_key, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	free_map(&vars);
	return (0);
}
