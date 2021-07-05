#include "../includes/so_long.h"

void	init_tex(t_data *data, t_tex *tex, char *path)
{
	if (!(tex->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &tex->width, &tex->height)))
	{
		printf("%s\n", path);
		printf("Texture path is wrong\n");
		// error_msg(data, "Textures path is wrong", true);
		exit(0);
	}
	if (!(tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->s_line, &tex->endian)))
	{
		printf("MLX don't work for on texture\n");
		// error_msg(data, "MLX don't work for tex", false);
		exit(0);
	}
}

void	init_sprites_and_tiles(t_data *data)
{
	init_tex(data, &data->grass, GRASS);
	init_tex(data, &data->rock, ROCK);

	init_tex(data, &data->right, RIGHTB);
	init_tex(data, &data->left, LEFTB);
	init_tex(data, &data->top, TOPB);
	init_tex(data, &data->bottom, BOTTOMB);
	init_tex(data, &data->toplb, TOPLB);
	init_tex(data, &data->toprb, TOPRB);
	init_tex(data, &data->bottomlb, BOTTOMLB);
	init_tex(data, &data->bottomrb, BOTTOMRB);

	init_tex(data, &data->collectible, COLLECTIBLE);
	init_tex(data, &data->collectible_taken, COLLECTIBLE_TAKEN);

	init_tex(data, &data->player.sprite_down[0], PLAYER_DOWN0);
	init_tex(data, &data->player.sprite_up[0], PLAYER_UP0);
	init_tex(data, &data->player.sprite_right[0], PLAYER_RIGHT0);
	init_tex(data, &data->player.sprite_left[0], PLAYER_LEFT0);

	init_tex(data, &data->player.sprite_down[1], PLAYER_DOWN1);
	init_tex(data, &data->player.sprite_up[1], PLAYER_UP1);
	init_tex(data, &data->player.sprite_right[1], PLAYER_RIGHT1);
	init_tex(data, &data->player.sprite_left[1], PLAYER_LEFT1);

	init_tex(data, &data->exit_close, EXIT_CLOSE);
	init_tex(data, &data->exit_open[0], EXIT_OPEN0);
	init_tex(data, &data->exit_open[1], EXIT_OPEN1);
	init_tex(data, &data->exit_open[2], EXIT_OPEN2);
	init_tex(data, &data->exit_open[3], EXIT_OPEN3);
	init_tex(data, &data->exit_open[4], EXIT_OPEN4);
	init_tex(data, &data->exit_open[5], EXIT_OPEN5);
	init_tex(data, &data->exit_open[6], EXIT_OPEN6);
	init_tex(data, &data->exit_open[7], EXIT_OPEN7);
	init_tex(data, &data->exit_open[8], EXIT_OPEN8);
	init_tex(data, &data->exit_open[9], EXIT_OPEN9);
	init_tex(data, &data->exit_open[10], EXIT_OPEN10);
	init_tex(data, &data->exit_open[11], EXIT_OPEN11);
	init_tex(data, &data->exit_open[12], EXIT_OPEN12);
	init_tex(data, &data->exit_open[13], EXIT_OPEN13);
}
