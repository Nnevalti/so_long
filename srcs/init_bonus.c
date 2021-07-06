#include "../includes/so_long.h"

void	init_display(t_data *d)
{
	d->display.img = mlx_new_image(d->mlx_ptr, d->win.width, d->win.height);
	d->display.addr = mlx_get_data_addr(d->display.img,
			&d->display.bpp, &d->display.s_line, &d->display.endian);
	if (!d->display.img || !d->display.addr)
	{
		free_map(d->map.map);
		handle_error(d, MLX_ERROR);
	}
}

void	init_mlx(t_data *d)
{
	d->mlx_ptr = mlx_init();
	d->win.width = d->map.width * TILE_SIZE;
	d->win.height = d->map.height * TILE_SIZE;
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->win.width,
			d->win.height, "So_Long");
}

t_data	init_data(const char *map)
{
	t_data	d;

	d.player_load = false;
	d.nb_moves = 0;
	d.nb_collectibles = 0;
	d.nb_collectibles_taken = 0;
	d.player.dir = DOWN;
	d.door_frame = 0;
	d.player.frame = 0;
	init_map(&d, map);
	init_mlx(&d);
	init_sprites_and_tiles(&d);
	init_display(&d);
	return (d);
}
