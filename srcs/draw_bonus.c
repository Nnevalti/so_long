#include "../includes/so_long.h"

void	draw_borders(t_data *d, int y, int x, int yb, int xb)
{
	if (xb == 0 && yb == 0)
		draw_tile(d, &d->toplb, y, x, yb, xb);
	else if (xb == 0 && yb == (int)d->map.height - 1)
		draw_tile(d, &d->bottomlb, y, x, yb, xb);
	else if (xb == 0)
		draw_tile(d, &d->left, y, x, yb, xb);
	else if (xb == (int)d->map.width - 1 && yb == 0)
		draw_tile(d, &d->toprb, y, x, yb, xb);
	else if (xb == (int)d->map.width - 1 && yb == (int)d->map.height - 1)
		draw_tile(d, &d->bottomrb, y, x, yb, xb);
	else if (xb == (int)d->map.width - 1)
		draw_tile(d, &d->right, y, x, yb, xb);
	else if (yb == 0)
		draw_tile(d, &d->top, y, x, yb, xb);
	else if (yb == (int)d->map.height - 1)
		draw_tile(d, &d->bottom, y, x, yb, xb);
	else
	{
		draw_tile(d, &d->grass, y, x, yb, xb);
		draw_sprite(d, &d->rock, y, x, yb, xb);
	}
}

void	draw_tiles(t_data *d, char tile, int yb, int xb)
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
				draw_borders(d, y, x, yb, xb);
			else
				draw_tile(d, &d->grass, y, x, yb, xb);
			x++;
		}
		y++;
	}
}

void	draw_sprites(t_data *d, char tile, int yb, int xb)
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
				draw_sprite(d, &d->collectible, y, x, yb, xb);
			else if (tile == 'T')
				draw_sprite(d, &d->collectible_taken, y, x, yb, xb);
			else if (tile == 'E')
			{
				if (d->nb_collectibles_taken == d->nb_collectibles)
					draw_sprite(d, &d->exit_open[d->door_frame],
						y, x, yb, xb);
				else
					draw_sprite(d, &d->exit_close, y, x, yb, xb);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *d)
{
	unsigned int		x;
	unsigned int		y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (d->player.dir == DOWN)
				draw_sprite(d, &d->player.sprite_down[d->player.frame],
					y, x, d->player.pos.y, d->player.pos.x);
			else if (d->player.dir == UP)
				draw_sprite(d, &d->player.sprite_up[d->player.frame],
					y, x, d->player.pos.y, d->player.pos.x);
			else if (d->player.dir == RIGHT)
				draw_sprite(d, &d->player.sprite_right[d->player.frame],
					y, x, d->player.pos.y, d->player.pos.x);
			else if (d->player.dir == LEFT)
				draw_sprite(d, &d->player.sprite_left[d->player.frame],
					y, x, d->player.pos.y, d->player.pos.x);
			x++;
		}
		y++;
	}
}

int	draw(t_data *d)
{
	unsigned int		y;
	unsigned int		x;

	y = 0;
	while (y < d->map.height)
	{
		x = 0;
		while (x < d->map.width)
		{
			draw_tiles(d, d->map.map[y][x], y, x);
			if (d->map.map[y][x] != 1)
				draw_sprites(d, d->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
	draw_player(d);
	display_nb_move(d);
	handle_frame(d);
	mlx_do_sync(d->mlx_ptr);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
		d->display.img, 0, 0);
	return (0);
}
