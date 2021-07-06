#include "../includes/so_long.h"

int	main(int ac, char const **av)
{
	t_data		d;

	if (ac != 2)
	{
		printf("Error\nInvalid numbers of arguments\n");
		printf("Usage: ./so_long [map.ber]\n");
	}
	else
	{
		d = init_data(av[1]);
		mlx_hook(d.win_ptr, 17, 0, exit_game, &d);
		mlx_key_hook(d.win_ptr, update, &d);
		mlx_loop_hook(d.mlx_ptr, draw, &d);
		mlx_loop(d.mlx_ptr);
	}
	return (0);
}
