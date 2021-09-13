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

void free_exit_tex(t_data *d)
{
	if (d->exit_close.load == true)
		mlx_destroy_image(d->mlx_ptr, d->exit_close.img);
	while (i != 13)
	{
		if (d->exit_open[i].load == true)
			mlx_destroy_image(d->mlx_ptr, d->exit_open[i].img);
		i++;
	}
}
void	free_tex(t_data *d)
{
	unsigned int i = 0;

	free_tex_border(d);
	free_exit_tex(d);
	free_tex_player(d);
	if (d->collectible.load == true)
		mlx_destroy_image(d->mlx_ptr, d->collectible.img);
	if (d->collectible_taken.load == true)
		mlx_destroy_image(d->mlx_ptr, d->collectible_taken.img);
}
