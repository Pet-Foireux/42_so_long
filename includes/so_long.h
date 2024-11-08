/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:55:49 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/08 12:36:41 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*coin_img;
	void	*sortit_img;
	int		player_x;
	int		player_y;
	int		last_x;
	int		last_y;
	int		player_speed;
	char	**map;
	int		width;
	int		height;
	int		*conteur;
	int		conteur_p;
	int		conteur_e;
	int		conteur_pieces;
	int		sortit_x;
	int		sortit_y;
	int		x;
	int		y;
}	t_vars;

int		handle_key(int key, t_vars *vars);
void	handle_exit(t_vars *vars);
int		can_move_to(t_vars *vars, int new_x, int new_y);
void	update_player_position(t_vars *vars, int new_x, int new_y);
void	position_player(t_vars *vars);
void	render_map(t_vars *vars);
int		render_next_frame(t_vars *vars);
void	init_window(t_vars *vars);
void	init_map(t_vars *vars, char **initial_map);
void	free_map(t_vars *vars);
void	check_borders(t_vars *vars);
void	ft_exit_fail(t_vars *vars);
void	ft_exit_succes(t_vars *vars);
void	check_lettre(t_vars *vars);
void	init_e(t_vars *vars);
void	print_img(t_vars *vars, void *img, int x, int y);
int		ft_strlen(char *str);
void	check_format(t_vars *vars);

#endif
