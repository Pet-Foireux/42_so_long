/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 07:42:45 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/20 13:15:47 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_borders(t_init *init)
{
	int	i;

	i = 0;
	while (i < init->widht)
	{
		if (init->map[0][i] != '1' || init->map[init->height - 1][i] != '1')
		{
			ft_printf("Ses pas fermer le roh.\n");
			free_map(init);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < init->height)
	{
		if (init->map[i][0] != '1' || init->map[i][init->widht - 1] != '1')
		{
			ft_printf("Ses pas fermer le roh.\n");
			free_map(init);
			exit(0);
		}
		i++;
	}
}

void	check_all(t_init *init)
{
	if (!init->map || init->height <= 0 || init->widht <= 0)
	{
		ft_printf("Erreur: La carte n'est pas correctement initialisée.\n");
		free_map(init);
		exit(0);
	}
	check_borders(init);
	check_carrer_de_la_mort(init);
	check_format(init);
}

void	check_carrer_de_la_mort(t_init *init)
{
	if (init->widht == init->height)
	{
		ft_printf("C'est trop carrer la.\n");
		free_map(init);
		exit(0);
	}
}

void	check_format(t_init *init)
{
	int	i;
	int	first_line;
	int	actually_line;

	if (init->height == 0)
	{
		ft_printf("Y'a r la mon reuf.\n");
		free_map(init);
		exit(0);
	}
	first_line = ft_strlen(init->map[0]);
	i = 1;
	while (i < init->height)
	{
		actually_line = ft_strlen(init->map[i]);
		if (actually_line != first_line)
		{
			ft_printf("C'est pas un rectangle chef.\n");
			free_map(init);
			exit(0);
		}
		i++;
	}
}

void	check_count(t_init *init, t_count *count)
{
	if (count->count_player != 1)
	{
		ft_printf("tu a %d joeurs\n", count->count_player);
		ft_exit(init);
	}
	else if (count->count_exit != 1)
	{
		ft_printf("Ta cru j'acceptais plusieurs sortit\n");
		ft_exit(init);
	}
}
