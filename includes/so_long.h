#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef enum	e_bool
{
	true,
	false
}				t_bool;

typedef enum	e_dir
{
	north,
	south,
	east,
	west
}				t_dir;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_win
{
	int			height;
	int			width;
}				t_win;

typedef struct	s_player
{
	t_pos		pos;
	t_dir		dir;
	double		move_speed;
}				t_player;

typedef struct	s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		endian;
	int		s_line;
	t_bool	load;
}				t_tex;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	t_bool		load;
}				t_color;

typedef struct	s_key
{
	t_bool		up;
	t_bool		down;
	t_bool		left;
	t_bool		right;
}				t_key;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_win		win;

	char		*map_buf;
	char		**map;

	t_key		key;

	t_player	player;

	t_tex		display;

	t_tex		tiles_wall;
	t_tex		tiles_floor;
	t_tex		tiles_collectibles;

	t_bool		success;
	t_bool		gameover;
	unsigned int	nb_moves;
}				t_data;

#endif
