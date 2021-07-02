#include "../includes/so_long.h"

int main(int ac, char const **av)
{
	t_data		data;

	if (ac != 2)
		printf("Error\nInvalid numbers of arguments\nUsage: ./so_long [map.ber]\n");
	else
	{
		data = init_data(av[1]);
		// mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
		// mlx_hook(data.win_ptr, 3, 0, key_released, &data);
		// mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
		// mlx_loop_hook(data.mlx_ptr, game, &data);
		mlx_loop(data.mlx_ptr);
	}
	return 0;
}
