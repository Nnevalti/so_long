#include "../includes/so_long.h"

int	ft_return(char **str, char **line)
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

int	readline(int fd, char **str, char **buff)
{
	int		res;
	char	*tmp;

	res = read(fd, *buff, BUFFER_SIZE);
	while (res > 0)
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
		res = read(fd, *buff, BUFFER_SIZE);
	}
	free(*buff);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	int				res;
	static char		*str;
	char			*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
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
