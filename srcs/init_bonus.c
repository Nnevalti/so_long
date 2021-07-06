#include "../includes/so_long.h"

void	init_display(t_data *d)
{
	d->display.img = mlx_new_image(d->mlx_ptr, d->win.width, d->win.height);
	d->display.addr = mlx_get_data_addr(d->display.img,
			&d->display.bpp, &d->display.s_line, &d->display.endian);
	if (!d->display.img || !d->display.addr)
		handle_error(d, MLX_ERROR);
	d->display_load = true;
}

void	init_mlx(t_data *d)
{
	d->mlx_ptr = mlx_init();
	d->win.width = d->map.width * TILE_SIZE;
	d->win.height = d->map.height * TILE_SIZE;
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->win.width,
			d->win.height, "So_Long");
	d->win_load = true;
}

void	init_load_tex2(t_data *d)
{
	d->exit_open[0].load = false;
	d->exit_open[1].load = false;
	d->exit_open[2].load = false;
	d->exit_open[3].load = false;
	d->exit_open[4].load = false;
	d->exit_open[5].load = false;
	d->exit_open[6].load = false;
	d->exit_open[7].load = false;
	d->exit_open[8].load = false;
	d->exit_open[9].load = false;
	d->exit_open[10].load = false;
	d->exit_open[11].load = false;
	d->exit_open[12].load = false;
	d->exit_open[13].load = false;
	d->collectible.load = false;
	d->collectible_taken.load = false;
}

void	init_load_tex(t_data *d)
{
	d->grass.load = false;
	d->rock.load = false;
	d->right.load = false;
	d->left.load = false;
	d->top.load = false;
	d->bottom.load = false;
	d->toplb.load = false;
	d->toprb.load = false;
	d->bottomlb.load = false;
	d->bottomrb.load = false;
	d->player.sprite_down[0].load = false;
	d->player.sprite_down[1].load = false;
	d->player.sprite_up[0].load = false;
	d->player.sprite_up[1].load = false;
	d->player.sprite_left[0].load = false;
	d->player.sprite_left[1].load = false;
	d->player.sprite_right[0].load = false;
	d->player.sprite_right[1].load = false;
	d->exit_close.load = false;
}

t_data	init_data(const char *map)
{
	t_data	d;

	d.player_load = false;
	d.exit_load = false;
	d.map_load = false;
	d.display_load = false;
	d.win_load = false;
	d.nb_moves = 0;
	d.nb_collectibles = 0;
	d.nb_collectibles_taken = 0;
	d.player.dir = DOWN;
	d.door_frame = 0;
	d.player.frame = 0;
	init_load_tex(&d);
	init_load_tex2(&d);
	init_map(&d, map);
	init_mlx(&d);
	init_sprites_and_tiles(&d);
	init_display(&d);
	return (d);
}
