#include "../includes/so_long.h"

void	up(t_data *d)
{
	if (d->map.map[d->player.pos.y - 1][d->player.pos.x] != '1')
	{
		d->player.pos.y--;
		d->nb_moves++;
	}
	d->player.dir = UP;
}

void	down(t_data *d)
{
	if (d->map.map[d->player.pos.y + 1][d->player.pos.x] != '1')
	{
		d->player.pos.y++;
		d->nb_moves++;
	}
	d->player.dir = DOWN;
}

void	right(t_data *d)
{
	if (d->map.map[d->player.pos.y][d->player.pos.x + 1] != '1')
	{
		d->player.pos.x++;
		d->nb_moves++;
	}
	d->player.dir = RIGHT;
}

void	left(t_data *d)
{
	if (d->map.map[d->player.pos.y][d->player.pos.x - 1] != '1')
	{
		d->player.pos.x--;
		d->nb_moves++;
	}
	d->player.dir = LEFT;
}

int	update(int key, t_data *d)
{
	if (key == ESCAPE_KEY)
		exit_game(d);
	else if (key == UP_KEY)
		up(d);
	else if (key == DOWN_KEY)
		down(d);
	else if (key == RIGHT_KEY)
		right(d);
	else if (key == LEFT_KEY)
		left(d);
	printf("nb_moves = %d\n", d->nb_moves);
	if (d->map.map[d->player.pos.y][d->player.pos.x] == 'C')
	{
		d->map.map[d->player.pos.y][d->player.pos.x] = 'T';
		d->nb_collectibles_taken++;
	}
	if (d->map.map[d->player.pos.y][d->player.pos.x] == 'E'
		&& d->nb_collectibles_taken == d->nb_collectibles)
	{
		printf("WIN\n");
		exit_game(d);
	}
	return (1);
}
