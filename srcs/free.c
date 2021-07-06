#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tex_border(t_data *d)
{
	if (d->grass.load == true)
		mlx_destroy_image(d->mlx_ptr, d->grass.img);
	if (d->rock.load == true)
		mlx_destroy_image(d->mlx_ptr, d->rock.img);
	if (d->right.load == true)
		mlx_destroy_image(d->mlx_ptr, d->right.img);
	if (d->left.load == true)
		mlx_destroy_image(d->mlx_ptr, d->left.img);
	if (d->top.load == true)
		mlx_destroy_image(d->mlx_ptr, d->top.img);
	if (d->bottom.load == true)
		mlx_destroy_image(d->mlx_ptr, d->bottom.img);
	if (d->toplb.load == true)
		mlx_destroy_image(d->mlx_ptr, d->toplb.img);
	if (d->toprb.load == true)
		mlx_destroy_image(d->mlx_ptr, d->toprb.img);
	if (d->bottomlb.load == true)
		mlx_destroy_image(d->mlx_ptr, d->bottomlb.img);
	if (d->bottomrb.load == true)
		mlx_destroy_image(d->mlx_ptr, d->bottomrb.img);
}

void	free_tex_player(t_data *d)
{
	if (d->player.sprite_down[0].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_down[0].img);
	if (d->player.sprite_down[1].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_down[1].img);
	if (d->player.sprite_up[0].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_up[0].img);
	if (d->player.sprite_up[1].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_up[1].img);
	if (d->player.sprite_left[0].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_left[0].img);
	if (d->player.sprite_left[1].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_left[1].img);
	if (d->player.sprite_right[0].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_right[0].img);
	if (d->player.sprite_right[1].load == true)
		mlx_destroy_image(d->mlx_ptr, d->player.sprite_right[1].img);
}

void	free_tex_exit(t_data *d)
{
	if (d->exit_close.load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_close.img);
	if (d->exit_open[0].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[0].img);
	if (d->exit_open[1].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[1].img);
	if (d->exit_open[2].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[2].img);
	if (d->exit_open[3].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[3].img);
	if (d->exit_open[4].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[4].img);
	if (d->exit_open[5].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[5].img);
	if (d->exit_open[6].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[6].img);
	if (d->exit_open[7].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[7].img);
	if (d->exit_open[8].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[8].img);
	if (d->exit_open[9].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[9].img);
	if (d->exit_open[10].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[10].img);
}

void	free_tex(t_data *d)
{
	free_tex_border(d);
	free_tex_exit(d);
	if (d->exit_open[11].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[11].img);
	if (d->exit_open[12].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[12].img);
	if (d->exit_open[13].load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_open[13].img);
	free_tex_player(d);
	if (d->collectible.load == true)
		mlx_destroy_image(d->mlx_ptr, d->collectible.img);
	if (d->collectible_taken.load == true)
		mlx_destroy_image(d->mlx_ptr, d->collectible_taken.img);
}
