/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:16:17 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/18 12:25:24 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../besoin/ft_printf/ft_printf.h"
# include "../besoin/gnl/get_next_line.h"
# include "../besoin/libft/libft.h"

typedef struct s_count
{
	int		count_piece;
	int		count_exit;
	int		count_player;
}	t_count;

typedef struct s_init
{
	t_count	count;
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;
	char	**map;
	int		height;
	int		widht;
}	t_init;

void	check_borders(t_init *init);
void	check_carrer_de_la_mort(t_init *init);
void	check_format(t_init *init);
void	check_count(t_init *init, t_count *count);
void	check_all(t_init *init);
void	init_xpm(t_init *init);
void	check_init(t_init *init);
void	init_count_move(t_init *init, t_count *count);
void	free_map(t_init *init);
int		ft_exit(t_init *init);
int		main(int argc, char **argv);
int		get_height(char **argv);
void	check_args(int argc, char **argv);
char	**ft_malloc(t_init *init);
void	parse_map(t_init *init, char **argv);
void	check_fd(int fd);
void	print(t_init *init, void *img, int x, int y);
void	print_map(t_init *init, t_count *count);
void	print_wall(t_init *init, int x, int y);
void	print_floor(t_init *init, int x, int y);
void	print_coin(t_init *init, t_count *count, int x, int y);
void	print_exit(t_init *init, t_count *count, int x, int y);
void	print_player(t_init *init, t_count *count, int x, int y);

#endif
