#include "../includes/so_long.h"

void	draw_tile(t_data *data, t_tex *tex, int y, int x, int yb, int xb)
{
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + (y * tex->s_line)];
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + 1 + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + 1 + (y * tex->s_line)];
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + 2 + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + 2 + (y * tex->s_line)];
}

void	draw_change(t_data *data, t_tex *tex, int y, int x, int yb, int xb)
{
	if (tex->addr[(x * tex->bpp >> 3) + (y * tex->s_line)] == 0
	&& tex->addr[(x * tex->bpp >> 3) + 1 + (y * tex->s_line)] == 0
	&& tex->addr[(x * tex->bpp >> 3) + 2 + (y * tex->s_line)] == 0)
		return ;
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + (y * tex->s_line)];
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + 1 + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + 1 + (y * tex->s_line)];
	data->display.addr[((x + (xb * TILE_SIZE)) * data->display.bpp >> 3) + 2 + ((y + (yb * TILE_SIZE)) * data->display.s_line)] =
	tex->addr[(x * tex->bpp >> 3) + 2 + (y * tex->s_line)];
}

void draw_borders(t_data *data, int y, int x, int yb, int xb)
{
	if (xb == 0 && yb == 0)
		draw_tile(data, &data->toplb, y, x, yb, xb);
	else if (xb == 0 && yb == (int)data->map.height - 1)
		draw_tile(data, &data->bottomlb, y, x, yb, xb);
	else if (xb == 0)
		draw_tile(data, &data->left, y, x, yb, xb);
	else if (xb == (int)data->map.width - 1 && yb == 0)
		draw_tile(data, &data->toprb, y, x, yb, xb);
	else if (xb == (int)data->map.width - 1 && yb == (int)data->map.height - 1)
		draw_tile(data, &data->bottomrb, y, x, yb, xb);
	else if (xb == (int)data->map.width - 1)
			draw_tile(data, &data->right, y, x, yb, xb);
	else if (yb == 0)
		draw_tile(data, &data->top, y, x, yb, xb);
	else if (yb == (int)data->map.height - 1)
		draw_tile(data, &data->bottom, y, x, yb, xb);
	else
	{
		draw_tile(data, &data->grass, y, x, yb, xb);
		draw_change(data, &data->rock, y, x, yb, xb);
	}
}

void	draw_tiles(t_data *data, char tile, int yb, int xb)
{
	unsigned int		x;
	unsigned int		y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (tile == '1')
				draw_borders(data, y, x, yb, xb);
			else
				draw_tile(data, &data->grass, y, x, yb, xb);
			x++;
		}
		y++;
	}
}

void	draw_sprites(t_data *data, char tile, int yb, int xb)
{
	unsigned int		x;
	unsigned int		y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (tile == 'C')
				draw_change(data, &data->collectible, y, x, yb, xb);
			else if (tile == 'T')
				draw_change(data, &data->collectible_taken, y, x, yb, xb);
			else if (tile == 'E')
			{
				if (data->nb_collectibles_taken == data->nb_collectibles)
					draw_change(data, &data->exit_open[data->door_frame], y, x, yb, xb);
				else
					draw_change(data, &data->exit_close, y, x, yb, xb);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	unsigned int		x;
	unsigned int		y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (data->player.dir == DOWN)
					draw_change(data, &data->player.sprite_down[data->player.frame], y, x,
						data->player.pos.y, data->player.pos.x);
			else if (data->player.dir == UP)
					draw_change(data, &data->player.sprite_up[data->player.frame], y, x,
						data->player.pos.y, data->player.pos.x);
			else if (data->player.dir == RIGHT)
					draw_change(data, &data->player.sprite_right[data->player.frame], y, x,
						data->player.pos.y, data->player.pos.x);
			else if (data->player.dir == LEFT)
					draw_change(data, &data->player.sprite_left[data->player.frame], y, x,
						data->player.pos.y, data->player.pos.x);
			x++;
		}
		y++;
	}
}

int		draw(t_data *data)
{
	unsigned int		y;
	unsigned int		x;
	static int i = 0;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			draw_tiles(data, data->map.map[y][x], y, x);
			if (data->map.map[y][x] != 1)
				draw_sprites(data, data->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
	draw_player(data);
	i++;
	if ((i % 10) == 0)
	{
		i = 0;
		data->player.frame = (data->player.frame + 1) % 2;

	}
	if (data->nb_collectibles_taken == data->nb_collectibles
		&& data->door_frame != 13)
		data->door_frame++;
	mlx_do_sync(data->mlx_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->display.img, 0, 0);
	return (0);
}
