#include "../includes/so_long.h"

void create_map(int fd, t_data *data)
{
	char	*line;
	char	*tmp;

	get_next_line(fd, &line);
	data->map.height = 1;
	data->map.width = ft_strlen(line);
	data->map.buff = ft_strdup(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) != data->map.width)
		{
			printf("Error: Invalid map\n");
			free(line);
			free(data->map.buff);
			exit(0);
		}
		tmp = ft_strjoin(data->map.buff, "\n");
		free(data->map.buff);
		data->map.buff = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		data->map.height++;
	}
	free(line);
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

void	init_map(int fd, t_data *data)
{

	create_map(fd, data);
	malloc_map(data);
	fill_map(data);
	// check_map(data);
	//for (int i = 0; i < (int)data->map.height; i++)
	//	printf("%s\n", data->map.map[i]);
}
