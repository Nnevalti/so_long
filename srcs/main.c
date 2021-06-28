#include "../includes/so_long.h"
#include "../libft/libft.h"

void	init_data(const char *map)
{
	// t_data	data;
	int		fd;

	if (ft_strcmp((map + (ft_strlen(map) - 4)), ".ber"))
		printf("Error\nInvalid map format\n");
	else if ((fd = open(map, O_RDONLY)) == -1)
		printf("Error\nFile does not exist\n");
	// return (data);
}

int main(int ac, char const **av)
{
	// t_data		data;

	if (ac != 2)
		printf("Error\nInvalid numbers of arguments\nUsage: ./so_long [map.ber]\n");
	else
	{
		// data =
		init_data(av[1]);
	}
	return 0;
}
