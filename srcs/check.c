/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:27:27 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/08 12:27:27 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_borders(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->width)
	{
		if (vars->map[0][i] != '1' || vars->map[vars->height - 1][i] != '1')
		{
			printf("Map not close.\n");
			ft_exit_succes(vars);
		}
		i++;
	}
	i = 0;
	while (i < vars->height)
	{
		if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
		{
			printf("Map not close.\n");
			ft_exit_succes(vars);
		}
		i++;
	}
}

void	check_format(t_vars *vars)
{
	int	i;
	int	first_line;

	if (vars->height == 0)
	{
		printf("Map is empty.\n");
		ft_exit_fail(vars);
	}
	first_line = ft_strlen(vars->map[0]);
	i = 1;
	while (i < vars->height)
	{
		if (ft_strlen(vars->map[i]) != first_line)
		{
			printf("Map is not rectangle.\n");
			ft_exit_fail(vars);
		}
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
