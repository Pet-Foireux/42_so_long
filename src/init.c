
#include "../include/so_long.h"

void	init_xpm(t_init *init)
{
	int	widht;
	int	height;

	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, init->widht * 32,
			init->height * 32, "so_long");
	init->coin_img = mlx_xpm_file_to_image(init->mlx, "besoin/struct/coin.xpm",
			&widht, &height);
	init->exit_img = mlx_xpm_file_to_image(init->mlx, "besoin/struct/exit.xpm",
			&widht, &height);
	init->floor_img = mlx_xpm_file_to_image(init->mlx,
			"besoin/struct/floor.xpm", &widht, &height);
	init->wall_img = mlx_xpm_file_to_image(init->mlx, "besoin/struct/wall.xpm",
			&widht, &height);
	init->player_img = mlx_xpm_file_to_image(init->mlx,
			"besoin/struct/player.xpm", &widht, &height);
	check_init(init);
}

void	check_init(t_init *init)
{
	if (!init->coin_img || !init->exit_img || !init->wall_img
		|| !init->floor_img || !init->player_img)
	{
		ft_printf("Error\nImages XPM.\n");
		ft_exit(init);
	}
}

void	init_count_move(t_init *init, t_count *count, t_move *move)
{
	init->widht = 0;
	init->height = 0;
	count->count_exit = 0;
	count->count_piece = 0;
	move->count_player = 0;
	init->pieces_trouvees = 0;
	init->sortie_trouvee = 0;
	init->player_trouvee = 0;
}
