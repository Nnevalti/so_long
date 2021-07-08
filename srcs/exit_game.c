#include "../includes/so_long.h"

int	exit_game(t_data *d)
{
	if (d->map_load == true)
		free_map(d->map.map);
	free_tex(d);
	if (d->display_load == true)
		mlx_destroy_image(d->mlx_ptr, d->display.img);
	if (d->win_load == true)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	system("leaks so_long_bonus");
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
