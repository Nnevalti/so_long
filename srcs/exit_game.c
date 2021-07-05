#include "../includes/so_long.h"

int		exit_game(t_data *data)
{
	(void)data;
	// system("leaks so_long");
	exit(0);
}

void		handle_error(t_data *data, int error)
{
	printf("Error\n");
	if (error == INVALID_MAP_FORMAT)
		printf("Invalid map format\n");
	else if (error == INVALID_MAP_FILE)
		printf("File does not exist\n");
	else if (error == INVALID_MAP)
		printf("Map is invalid\n");
	else if (error == MLX_ERROR)
		printf("Couldn't initialize mlx\n");
	exit_game(data);
}
