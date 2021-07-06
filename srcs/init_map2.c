#include "../includes/so_long.h"

void	check_map_file(t_data *d, const char *map)
{
	if (ft_strcmp((map + (ft_strlen(map) - 4)), ".ber"))
		handle_error(d, INVALID_MAP_FORMAT);
	d->map.fd = open(map, O_RDONLY);
	if (d->map.fd == -1)
		handle_error(d, INVALID_MAP_FILE);
}

void	create_map(t_data *d)
{
	char	*line;
	char	*tmp;

	get_next_line(d->map.fd, &line);
	d->map.height = 1;
	d->map.width = ft_strlen(line);
	d->map.buff = ft_strdup(line);
	free(line);
	while (get_next_line(d->map.fd, &line))
	{
		if (ft_strlen(line) != d->map.width)
		{
			free(line);
			free(d->map.buff);
			close(d->map.fd);
			handle_error(d, INVALID_MAP);
		}
		tmp = ft_strjoin(d->map.buff, "\n");
		free(d->map.buff);
		d->map.buff = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		d->map.height++;
	}
	free(line);
	close(d->map.fd);
}

void	malloc_map(t_data *d)
{
	unsigned int		i;

	i = 0;
	d->map.map = malloc(sizeof(char *) * (d->map.height + 1));
	if (d->map.map == NULL)
	{
		free(d->map.buff);
		handle_error(d, MALLOC_FAIL);
	}
	d->map.map[d->map.height] = NULL;
	while (i < d->map.height)
	{
		d->map.map[i] = malloc(sizeof(char) * (d->map.width + 1));
		if (d->map.map[i] == NULL)
		{
			free(d->map.buff);
			free(d->map.map);
			handle_error(d, MALLOC_FAIL);
		}
		d->map.map[i][d->map.width] = '\0';
		i++;
	}
}

void	fill_map(t_data *d)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	i;

	i = 0;
	y = 0;
	while (y < d->map.height)
	{
		x = 0;
		while (x < d->map.width)
		{
			if (d->map.buff[(y * d->map.width) + x + i] == '\n')
				i++;
			d->map.map[y][x] = d->map.buff[(y * d->map.width) + x + i];
			x++;
		}
		y++;
	}
	free(d->map.buff);
	d->map_load = true;
}
