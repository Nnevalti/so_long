#include "../includes/so_long.h"

int	exit_game(t_data *d)
{
	free_tex(d);
	exit(0);
}

void	handle_error(t_data *d, int error)
{
	printf("Error\n");
	if (error == INVALID_MAP_FORMAT)
		printf("Invalid map format\n");
	else if (error == INVALID_MAP_FILE)
		printf("File does not exist\n");
	else if (error == INVALID_MAP)
		printf("Map is invalid\n");
	else if (error == MALLOC_FAIL)
		printf("Malloc failed\n");
	else if (error == MLX_ERROR)
		printf("Couldn't initialize mlx\n");
	else if (error == PLAYER_DOUBLE_INITIALIZED)
		printf("Player is initialized twice\n");
	else if (error == PLAYER_UNINITIALIZED)
		printf("Player is unitialized\n");
	else if (error == NO_EXIT)
		printf("No exit on the map\n");
	else if (error == NO_COLLECTIBLES)
		printf("No collectibles on the map\n");
	else if (error == TEX_PATH_WRONG)
		printf("Texture path is wrong\n");
	exit_game(d);
}
