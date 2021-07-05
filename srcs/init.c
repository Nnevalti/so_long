#include "../includes/so_long.h"

void		init_display(t_data *data)
{
	if (!(data->display.img = mlx_new_image(data->mlx_ptr,
		data->win.width, data->win.height))
		|| !(data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.s_line, &data->display.endian)))
		handle_error(data, MLX_ERROR);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win.width = data->map.width * TILE_SIZE;
	data->win.height = data->map.height * TILE_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width, data->win.height, "So_Long");
}

t_data	init_data(const char *map)
{
	t_data	data;

	data.player_load = false;
	data.nb_moves = 0;
	data.nb_collectibles = 0;
	data.nb_collectibles_taken = 0;
	data.player.dir = DOWN;

	data.door_frame = 0;
	data.player.frame = 0;

	init_map(&data, map);
	init_mlx(&data);
	init_sprites_and_tiles(&data);
	init_display(&data);
	return (data);
}
