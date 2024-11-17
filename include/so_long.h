/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:16:17 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/17 06:09:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../besoin/ft_printf/ft_printf.h"
# include "../besoin/gnl/get_next_line.h"
# include "../besoin/libft/libft.h"

typedef struct s_init
{
    void    *mlx;
    void    *win;
    void    *player_img;
    void    *coin_img;
    void    *exit_img;
    void    *wall_img;
    void    *floor_img;
    char    **map;
    int     height;
    int     widht;
}   t_init;

int     main(int argc, char **argv);
void    check_args(int argc, char **argv);
void    parse_map(t_init *init, char **argv);
void    check_fd(int fd);
void    init_xpm(t_init *init);
void	print_map(t_init *init);

#endif
