/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:32 by mpapin            #+#    #+#             */
/*   Updated: 2024/12/12 17:29:45 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_init *init, int x, int y)
{
	if (x < 0 || x >= init->height || y < 0 || y >= init->widht)
		return ;
	if (init->visited[x][y] == 'P')
		init->player_trouvee = 1;
	if (init->visited[x][y] == '1' || init->visited[x][y] == '2')
		return ;
	if (init->visited[x][y] == 'C')
		(init->pieces_trouvees)++;
	if (init->visited[x][y] == 'E')
	{
		init->sortie_trouvee = 1;
		return ;
	}
	init->visited[x][y] = '2';
	flood_fill(init, x + 1, y);
	flood_fill(init, x - 1, y);
	flood_fill(init, x, y + 1);
	flood_fill(init, x, y - 1);
}

void	check_chemin(t_init *init, t_move *move, t_count *count)
{
	flood_fill(init, move->p_x, move->p_y);
	if (init->player_trouvee != 1)
	{
		ft_printf("Error\nSortit innaccessible.\n");
		ft_exit(init);
	}
	if (init->sortie_trouvee != 1)
	{
		ft_printf("Error\nSortit innaccessible.\n");
		ft_exit(init);
	}
	if (init->pieces_trouvees != count->count_piece)
	{
		ft_printf("Error\nPiece innaccessible.\n");
		ft_exit(init);
	}
	if (count->count_piece == 0)
	{
		ft_printf("Error\nEnvoi une pieces le sang.\n");
		ft_exit(init);
	}
}

void	map_to_visited(t_init *init)
{
	int		i;
	char	**visited;

	visited = malloc(sizeof(char *) * (init->height + 1));
	if (!visited)
	{
		ft_printf("Error\nProblème malloc visited\n");
		exit(1);
	}
	i = -1;
	while (++i < init->height)
	{
		visited[i] = malloc(sizeof(char) * (init->widht + 1));
		if (!visited[i])
		{
			ft_printf("Error\nProblème malloc visited[i]\n");
			exit(1);
		}
		ft_strlcpy(visited[i], init->map[i], init->widht + 1);
	}
	visited[i] = NULL;
	init->visited = visited;
}
