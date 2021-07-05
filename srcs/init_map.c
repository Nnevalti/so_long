#include "../includes/so_long.h"

void	check_map_file(t_data *data, const char *map)
{
	if (ft_strcmp((map + (ft_strlen(map) - 4)), ".ber"))
		handle_error(data, INVALID_MAP_FORMAT);
	data->map.fd = open(map, O_RDONLY);
	if (data->map.fd == -1)
		handle_error(data, INVALID_MAP_FILE);
}

void create_map(t_data *data)
{
	char	*line;
	char	*tmp;

	get_next_line(data->map.fd, &line);
	data->map.height = 1;
	data->map.width = ft_strlen(line);
	data->map.buff = ft_strdup(line);
	free(line);
	while (get_next_line(data->map.fd, &line))
	{
		if (ft_strlen(line) != data->map.width)
		{
			free(line);
			free(data->map.buff);
			handle_error(data, INVALID_MAP);
		}
		tmp = ft_strjoin(data->map.buff, "\n");
		free(data->map.buff);
		data->map.buff = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		data->map.height++;
	}
	free(line);
	close(data->map.fd);
}

void	malloc_map(t_data *data)
{
	unsigned int		i;

	i = 0;
	data->map.map = malloc(sizeof(char*) * data->map.height);
	if (data->map.map == NULL)
	{
		free(data->map.buff);
		exit(0);
	}
	while (i < data->map.height)
	{
		data->map.map[i] = malloc(sizeof(char) * data->map.width);
		if (data->map.map[i] == NULL)
		{
			free(data->map.buff);
			free(data->map.map);
			exit(0);
		}
		i++;
	}
}

void fill_map(t_data *data)
{
	unsigned int y;
	unsigned int x;
	unsigned int i;

	i = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.buff[(y * data->map.width) + x + i] == '\n')
				i++;
			data->map.map[y][x] = data->map.buff[(y * data->map.width) + x + i];
			x++;
		}
		y++;
	}
	free(data->map.buff);
}


int		is_charset(char c, char *charset)
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
void	init_player(t_data *data, unsigned int y, unsigned int x)
{
	data->player.pos.y = y;
	data->player.pos.x = x;
}

void	check_map_validity(t_data *data)
{
	unsigned int		y;
	unsigned int		x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (!is_charset(data->map.map[y][x], "01ECP"))
				handle_error(data, INVALID_MAP);
			if (data->map.map[y][x] == 'P' && data->player_load == false)
			{
				init_player(data, y, x);
				data->map.map[y][x] = '0';
				data->player_load = true;
			}
			else if (data->map.map[y][x] == 'P' && data->player_load == true)
			{
				handle_error(data, PLAYER_DOUBLE_INITIALIZED);
			}
			if (data->map.map[y][x] == 'C')
				data->nb_collectibles++;
			x++;
		}
		y++;
	}
	if (data->player_load == false)
		handle_error(data, PLAYER_UNINITIALIZED);
	if (data->nb_collectibles == 0)
		handle_error(data, NO_COLLECTIBLES);
}

void	init_map(t_data *data, char const *map)
{
	check_map_file(data, map);
	create_map(data);
	malloc_map(data);
	fill_map(data);
	check_map_validity(data);
	// DISPLAY MAP FOR DEBUG
	// for (int y = 0; y < (int)data->map.height; y++)
	// {
	// 	for (int x = 0; x < (int)data->map.width; x++)
	// 		printf("%c", data->map.map[y][x]);
	// 	printf("\n");
	// }
}
