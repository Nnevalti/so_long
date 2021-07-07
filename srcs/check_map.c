#include "../includes/so_long.h"

int	is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_top_bottom_border(t_data *d)
{
	unsigned int		x;

	x = 0;
	while (x < d->map.width)
	{
		if (d->map.map[0][x] != '1'
		|| d->map.map[d->map.height - 1][x] != '1')
			handle_error(d, INVALID_MAP);
		x++;
	}
}

void	check_right_left_border(t_data *d)
{
	unsigned int		y;

	y = 0;
	while (y < d->map.height)
	{
		if (d->map.map[y][0] != '1'
		|| d->map.map[y][d->map.width - 1] != '1')
			handle_error(d, INVALID_MAP);
		y++;
	}
}

void	check_tiles(t_data *d)
{
	unsigned int		y;
	unsigned int		x;

	y = 0;
	while (y < d->map.height)
	{
		x = 0;
		while (x < d->map.width)
		{
			if (!is_charset(d->map.map[y][x], "01ECP"))
				handle_error(d, INVALID_MAP);
			if (d->map.map[y][x] == 'P')
				init_player(d, y, x);
			if (d->map.map[y][x] == 'C')
				d->nb_collectibles++;
			if (d->map.map[y][x] == 'E')
				d->exit_load = true;
			x++;
		}
		y++;
	}
}

void	check_map_validity(t_data *d)
{
	check_top_bottom_border(d);
	check_right_left_border(d);
	check_tiles(d);
	if (d->player_load == false)
		handle_error(d, PLAYER_UNINITIALIZED);
	if (d->exit_load == false)
		handle_error(d, NO_EXIT);
	if (d->nb_collectibles == 0)
		handle_error(d, NO_COLLECTIBLES);
}
