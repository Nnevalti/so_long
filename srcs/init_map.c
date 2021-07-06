#include "../includes/so_long.h"

void	init_player(t_data *d, unsigned int y, unsigned int x)
{
	if (d->player_load == true)
	{
		free_map(d->map.map);
		handle_error(d, PLAYER_DOUBLE_INITIALIZED);
	}
	d->player.pos.y = y;
	d->player.pos.x = x;
	d->player_load = true;
	d->map.map[y][x] = '0';
}

void	init_map(t_data *d, char const *map)
{
	check_map_file(d, map);
	create_map(d);
	malloc_map(d);
	fill_map(d);
	check_map_validity(d);
}
