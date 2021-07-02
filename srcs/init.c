#include "../includes/so_long.h"

void init_tex(t_data *data, t_tex *tex, char *path)
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

void		init_display(t_data *data)
{
	if (!(data->display.img = mlx_new_image(data->mlx_ptr,
		data->win.width, data->win.height))
		|| !(data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.s_line, &data->display.endian)))
			exit(0);
		// exit_game(data);
}

void	draw_pix(t_data *data, t_tex *tex, int y, int x, int yb, int xb)
{
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + (y * tex->s_line)];
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + 1 + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + 1 + (y * tex->s_line)];
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + 2 + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + 2 + (y * tex->s_line)];
}

void draw_border(t_data *data, int y, int x, int yb, int xb)
{
	if (xb == 0)
	{
		if (yb == 0)
			draw_pix(data, &data->toplb, y, x, yb, xb);
		else if (yb == (int)data->map.height - 1)
			draw_pix(data, &data->bottomlb, y, x, yb, xb);
		else
			draw_pix(data, &data->left, y, x, yb, xb);
	}
	else if (xb == (int)data->map.width - 1)
	{
		if (yb == 0)
			draw_pix(data, &data->toprb, y, x, yb, xb);
		else if (yb == (int)data->map.height - 1)
			draw_pix(data, &data->bottomrb, y, x, yb, xb);
		else
			draw_pix(data, &data->right, y, x, yb, xb);
	}
	else if (yb == 0)
	{
		draw_pix(data, &data->top, y, x, yb, xb);
	}
	else if (yb == (int)data->map.height - 1)
	{
		draw_pix(data, &data->bottom, y, x, yb, xb);
	}
	else
		draw_pix(data, &data->rock, y, x, yb, xb);
}

void	draw_tile(t_data *data, char tile, int yb, int xb)
{
	unsigned int		x;
	unsigned int		y;

	(void)tile;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (tile == '1')
				draw_border(data, y, x, yb, xb);
			else if (tile == '0')
				draw_pix(data, &data->grass, y, x, yb, xb);
			else if (tile == 'C')
				draw_pix(data, &data->collectible, y, x, yb, xb);
			else if (tile == 'P')
				draw_pix(data, &data->player, y, x, yb, xb);
			else if (tile == 'E')
				draw_pix(data, &data->exit_close, y, x, yb, xb);
			x++;
		}
		y++;
	}
}

void	draw(t_data *data)
{
	unsigned int		y;
	unsigned int		x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			draw_tile(data, data->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win.width = data->map.width * TILE_SIZE;
	data->win.height = data->map.height * TILE_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width, data->win.height, "So_Long");

	init_tex(data, &data->grass, GRASS);
	init_tex(data, &data->rock, ROCK);

	init_tex(data, &data->right, RIGHT);
	init_tex(data, &data->left, LEFT);
	init_tex(data, &data->top, TOP);
	init_tex(data, &data->bottom, BOTTOM);
	init_tex(data, &data->toplb, TOPLB);
	init_tex(data, &data->toprb, TOPRB);
	init_tex(data, &data->bottomlb, BOTTOMLB);
	init_tex(data, &data->bottomrb, BOTTOMRB);

	init_tex(data, &data->collectible, COLLECTIBLE);
	init_tex(data, &data->collectible_taken, COLLECTIBLE_TAKEN);

	init_tex(data, &data->player, PLAYER);
	init_tex(data, &data->exit_close, EXIT_CLOSE);

	init_display(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->display.img, 0, 0);
}

t_data	init_data(const char *map)
{
	t_data	data;
	int		fd;

	if (ft_strcmp((map + (ft_strlen(map) - 4)), ".ber"))
	{
		printf("Error\nInvalid map format\n");
		exit(0);
	}
	if ((fd = open(map, O_RDONLY)) == -1)
	{
		printf("Error\nFile does not exist\n");
		exit(0);
	}
	// load file ?
	init_map(fd, &data);
	close(fd);
	init_mlx(&data);
	return (data);
}
