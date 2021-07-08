#include "../includes/so_long.h"

void	draw_borders(t_data *d)
{
	if (d->draw.x_t == 0 && d->draw.y_t == 0)
		draw_tile(d, &d->toplb);
	else if (d->draw.x_t == 0 && d->draw.y_t == d->map.height - 1)
		draw_tile(d, &d->bottomlb);
	else if (d->draw.x_t == 0)
		draw_tile(d, &d->left);
	else if (d->draw.x_t == d->map.width - 1 && d->draw.y_t == 0)
		draw_tile(d, &d->toprb);
	else if (d->draw.x_t == d->map.width - 1
		&& d->draw.y_t == d->map.height - 1)
		draw_tile(d, &d->bottomrb);
	else if (d->draw.x_t == d->map.width - 1)
		draw_tile(d, &d->right);
	else if (d->draw.y_t == 0)
		draw_tile(d, &d->top);
	else if (d->draw.y_t == d->map.height - 1)
		draw_tile(d, &d->bottom);
	else
	{
		draw_tile(d, &d->grass);
		draw_sprite(d, &d->rock);
	}
}

void	draw_tiles(t_data *d, char tile)
{
	d->draw.y_s = 0;
	while (d->draw.y_s < TILE_SIZE)
	{
		d->draw.x_s = 0;
		while (d->draw.x_s < TILE_SIZE)
		{
			if (tile == '1')
				draw_borders(d);
			else
				draw_tile(d, &d->grass);
			d->draw.x_s++;
		}
		d->draw.y_s++;
	}
}

void	draw_sprites(t_data *d, char tile)
{
	d->draw.y_s = 0;
	while (d->draw.y_s < TILE_SIZE)
	{
		d->draw.x_s = 0;
		while (d->draw.x_s < TILE_SIZE)
		{
			if (tile == 'C')
				draw_sprite(d, &d->collectible);
			else if (tile == 'T')
				draw_sprite(d, &d->collectible_taken);
			else if (tile == 'E')
			{
				if (d->nb_collectibles_taken == d->nb_collectibles)
					draw_sprite(d, &d->exit_open[d->door_frame]);
				else
					draw_sprite(d, &d->exit_close);
			}
			d->draw.x_s++;
		}
		d->draw.y_s++;
	}
}

void	draw_player(t_data *d)
{
	d->draw.y_s = 0;
	while (d->draw.y_s < TILE_SIZE)
	{
		d->draw.x_s = 0;
		while (d->draw.x_s < TILE_SIZE)
		{
			if (d->player.dir == DOWN)
				draw_player_sprite(d, &d->player.sprite_down[d->player.frame]);
			else if (d->player.dir == UP)
				draw_player_sprite(d, &d->player.sprite_up[d->player.frame]);
			else if (d->player.dir == RIGHT)
				draw_player_sprite(d, &d->player.sprite_right[d->player.frame]);
			else if (d->player.dir == LEFT)
				draw_player_sprite(d, &d->player.sprite_left[d->player.frame]);
			d->draw.x_s++;
		}
		d->draw.y_s++;
	}
}

int	draw(t_data *d)
{
	char	*n;

	d->draw.y_t = 0;
	while (d->draw.y_t < d->map.height)
	{
		d->draw.x_t = 0;
		while (d->draw.x_t < d->map.width)
		{
			draw_tiles(d, d->map.map[d->draw.y_t][d->draw.x_t]);
			if (d->map.map[d->draw.y_t][d->draw.x_t] != 1)
				draw_sprites(d, d->map.map[d->draw.y_t][d->draw.x_t]);
			d->draw.x_t++;
		}
		d->draw.y_t++;
	}
	draw_player(d);
	n = ft_itoa(d->nb_moves);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 7, 10, 0xFFFFFF, n);
	free(n);
	handle_frame(d);
	mlx_do_sync(d->mlx_ptr);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
		d->display.img, 0, 0);
	return (0);
}
