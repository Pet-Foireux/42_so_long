/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:16:17 by mpapin            #+#    #+#             */
/*   Updated: 2024/12/06 16:00:04 by mpapin           ###   ########.fr       */
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
}	t_count;

typedef struct s_init
{
	t_count		*count;
	void		*mlx;
	void		*win;
	void		*player_img;
	void		*coin_img;
	void		*exit_img;
	void		*wall_img;
	void		*floor_img;
	char		**map;
	char		**visited;
	int			exit_x;
	int			exit_y;
	int			height;
	int			widht;
	int			sortie_trouvee;
	int			pieces_trouvees;
	int			player_trouvee;
	char		*bonus_conteur;
}	t_init;

typedef struct s_move
{
	t_init	*init;
	t_count	*count;
	int		count_player;
	int		mouvements;
	int		last_x;
	int		last_y;
	int		player_x;
	int		player_y;
	int		p_x;
	int		p_y;
	int		new_x;
	int		new_y;
}	t_move;

void	check_borders(t_init *init);
void	check_carrer_de_la_mort(t_init *init);
void	check_format(t_init *init);
void	check_count(t_init *init, t_count *count, t_move *move);
void	check_all(t_init *init);
void	init_xpm(t_init *init);
void	check_init(t_init *init);
int		handle_key(int key, t_move *move);
int		ft_mouvements(t_move *move);
int		update(t_move *move);
int		can_move(t_move *move);
void	init_count_move(t_init *init, t_count *count, t_move *move);
int		exit_croix(t_init *init);
void	free_map(t_init *init);
int		ft_exit(t_init *init);
int		main(int argc, char **argv);
int		get_height(char **argv);
void	check_args(int argc);
char	**ft_malloc(t_init *init);
void	parse_map(t_init *init, char **argv);
void	check_fd(int fd);
void	print(t_init *init, void *img, int x, int y);
void	print_map(t_init *init, t_count *count, t_move *move);
void	print_wall(t_init *init, int x, int y);
void	print_floor(t_init *init, int x, int y);
void	print_coin(t_init *init, t_count *count, int x, int y);
void	print_exit(t_init *init, t_count *count, int x, int y);
void	print_player(t_init *init, t_move *move, int x, int y);
void	visited(t_init *init);
void	check_chemin(t_init *init, t_move *move, t_count *count);
void	flood_fill(t_init *init, int x, int y);
void	map_to_visited(t_init *init);
void	print_visited(t_init *init);

#endif
