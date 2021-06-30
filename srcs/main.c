#include "../includes/so_long.h"
#include "../libft/libft.h"
#define BUFFER_SIZE 512
// #include "get_next_line.h"

int		ft_return(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
		tmp = ft_strdup(&(*str)[i + 1]);
	else
		tmp = NULL;
	free(*str);
	*str = tmp;
	if (!*str)
		return (0);
	return (1);
}

int		readline(int fd, char **str, char **buff)
{
	int		res;
	char	*tmp;

	while ((res = read(fd, *buff, BUFFER_SIZE)) > 0)
	{
		(*buff)[res] = '\0';
		if (!*str || !**str)
		{
			tmp = ft_strdup(*buff);
			free(*str);
			*str = tmp;
		}
		else
		{
			tmp = ft_strjoin(*str, *buff);
			free(*str);
			*str = tmp;
		}
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(*buff);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	int				res;
	static char		*str;
	char			*buff;

	if (!(buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (-1);
	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	res = readline(fd, &str, &buff);
	if (res < 0)
		return (-1);
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_return(&str, line));
}
void	init_map(int fd, t_data *data)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	get_next_line(fd, &line);
	data->map_buf = ft_strdup(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin(data->map_buf, "\n");
		free(data->map_buf);
		data->map_buf = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	free(line);
	printf("%s\n", data->map_buf);
	system("leaks so_long");
}

t_data	init_data(const char *map)
{
	t_data	data;
	int		fd;

	if (ft_strcmp((map + (ft_strlen(map) - 4)), ".ber"))
	{
		printf("Error\nInvalid map format\n");
		exit(0);
	}
	if ((fd = open(map, O_RDONLY)) == -1)
	{
		printf("Error\nFile does not exist\n");
		exit(0);
	}
	init_map(fd, &data);

	// data.mlx_ptr = mlx_init();
	return (data);
}

int main(int ac, char const **av)
{
	t_data		data;

	if (ac != 2)
		printf("Error\nInvalid numbers of arguments\nUsage: ./so_long [map.ber]\n");
	else
	{
		data = init_data(av[1]);
	}
	return 0;
}
