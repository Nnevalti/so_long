#include "../includes/so_long.h"

void	init_tex(t_data *d, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(d->mlx_ptr, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		printf("%s\n", path);
		handle_error(d, TEX_PATH_WRONG);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->s_line, &tex->endian);
	if (!tex->addr)
		handle_error(d, MLX_ERROR);
	tex->load = true;
}

void	init_border_tex(t_data *d)
{
	init_tex(d, &d->grass, GRASS);
	init_tex(d, &d->rock, ROCK);
	init_tex(d, &d->right, RIGHTB);
	init_tex(d, &d->left, LEFTB);
	init_tex(d, &d->top, TOPB);
	init_tex(d, &d->bottom, BOTTOMB);
	init_tex(d, &d->toplb, TOPLB);
	init_tex(d, &d->toprb, TOPRB);
	init_tex(d, &d->bottomlb, BOTTOMLB);
	init_tex(d, &d->bottomrb, BOTTOMRB);
}

void	init_player_tex(t_data *d)
{
	init_tex(d, &d->player.sprite_up[0], PLAYER_UP0);
	init_tex(d, &d->player.sprite_up[1], PLAYER_UP1);
	init_tex(d, &d->player.sprite_down[0], PLAYER_DOWN0);
	init_tex(d, &d->player.sprite_down[1], PLAYER_DOWN1);
	init_tex(d, &d->player.sprite_left[0], PLAYER_LEFT0);
	init_tex(d, &d->player.sprite_left[1], PLAYER_LEFT1);
	init_tex(d, &d->player.sprite_right[0], PLAYER_RIGHT0);
	init_tex(d, &d->player.sprite_right[1], PLAYER_RIGHT1);
}

void	init_exit_tex(t_data *d)
{
	init_tex(d, &d->exit_close, EXIT_CLOSE);
	init_tex(d, &d->exit_open[0], EXIT_OPEN0);
	init_tex(d, &d->exit_open[1], EXIT_OPEN1);
	init_tex(d, &d->exit_open[2], EXIT_OPEN2);
	init_tex(d, &d->exit_open[3], EXIT_OPEN3);
	init_tex(d, &d->exit_open[4], EXIT_OPEN4);
	init_tex(d, &d->exit_open[5], EXIT_OPEN5);
	init_tex(d, &d->exit_open[6], EXIT_OPEN6);
	init_tex(d, &d->exit_open[7], EXIT_OPEN7);
	init_tex(d, &d->exit_open[8], EXIT_OPEN8);
	init_tex(d, &d->exit_open[9], EXIT_OPEN9);
	init_tex(d, &d->exit_open[10], EXIT_OPEN10);
	init_tex(d, &d->exit_open[11], EXIT_OPEN11);
	init_tex(d, &d->exit_open[12], EXIT_OPEN12);
	init_tex(d, &d->exit_open[13], EXIT_OPEN13);
}

void	init_sprites_and_tiles(t_data *d)
{
	init_border_tex(d);
	init_player_tex(d);
	init_exit_tex(d);
	init_tex(d, &d->collectible, COLLECTIBLE);
	init_tex(d, &d->collectible_taken, COLLECTIBLE_TAKEN);
}
