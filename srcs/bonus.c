#include "../includes/so_long.h"

void	handle_frame(t_data *d)
{
	static int	i = 0;

	i++;
	if ((i % 10) == 0)
	{
		i = 0;
		d->player.frame = (d->player.frame + 1) % 2;
	}
	if (d->nb_collectibles_taken == d->nb_collectibles
		&& d->door_frame != 13)
		d->door_frame++;
}

void	display_nb_move(t_data *d)
{
	int		y;
	int		x;

	y = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			d->display.addr[x * (d->display.bpp >> 3)
				+ y * d->display.s_line] = 0x000000 & 0xFF;
			d->display.addr[x * (d->display.bpp >> 3)
				+ y * d->display.s_line + 1] = (0x000000 >> 8) & 0xFF;
			d->display.addr[x * (d->display.bpp >> 3)
				+ y * d->display.s_line + 2] = (0x000000 >> 16) & 0xFF;
			x++;
		}
		y++;
	}
	mlx_string_put(d->mlx_ptr, d->win_ptr, 7, 10, 0xFFFFFF,
		ft_itoa(d->nb_moves));
}
