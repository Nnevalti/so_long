#include "../includes/so_long.h"

void	up(t_data *data)
{
	if (data->map.map[data->player.pos.y - 1][data->player.pos.x] != '1')
	{
		data->player.pos.y--;
		data->nb_moves++;
	}
	data->player.dir = UP;
}

void	down(t_data *data)
{
	if (data->map.map[data->player.pos.y + 1][data->player.pos.x] != '1')
	{
		data->player.pos.y++;
		data->nb_moves++;
	}
	data->player.dir = DOWN;
}

void	right(t_data *data)
{
	if (data->map.map[data->player.pos.y][data->player.pos.x + 1] != '1')
	{
		data->player.pos.x++;
		data->nb_moves++;
	}
	data->player.dir = RIGHT;
}

void	left(t_data *data)
{
	if (data->map.map[data->player.pos.y][data->player.pos.x - 1] != '1')
	{
		data->player.pos.x--;
		data->nb_moves++;
	}
	data->player.dir = LEFT;
}

int		update(int key, t_data *data)
{
	if (key == ESCAPE_KEY)
		exit_game(data);
	else if (key == UP_KEY)
		up(data);
	else if (key == DOWN_KEY)
		down(data);
	else if (key == RIGHT_KEY)
		right(data);
	else if (key == LEFT_KEY)
		left(data);
	printf("nb_moves = %d\n", data->nb_moves);
	if (data->map.map[data->player.pos.y][data->player.pos.x] == 'C')
	{
		data->map.map[data->player.pos.y][data->player.pos.x] = 'T';
		data->nb_collectibles_taken++;
	}
	if (data->map.map[data->player.pos.y][data->player.pos.x] == 'E'
		&& data->nb_collectibles_taken == data->nb_collectibles)
	{
		printf("WIN\n");
		exit_game(data);
	}

	return (1);
}
