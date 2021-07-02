#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"

# define BUFFER_SIZE 512
# define TILE_SIZE 32

# define LEFT_KEY 0
# define DOWN_KEY 1
# define RIGHT_KEY 2
# define UP_KEY 13
# define ESCAPE 53
/*
*
*	TEXTURES PATH
*
*/
// # define GRASS "./textures_xpm/grass.xpm"
// # define ROCK "./textures_xpm/rock.xpm"
# define GRASS "./textures_xpm/grass.xpm"
# define ROCK "./textures_xpm/rock.xpm"

/*
*	BORDER
*/
# define RIGHT "./textures_xpm/right_border.xpm"
# define LEFT "./textures_xpm/left_border.xpm"
# define TOP "./textures_xpm/top_border.xpm"
# define BOTTOM "./textures_xpm/bottom_border.xpm"

# define BOTTOMLB "./textures_xpm/bottom_left_border.xpm"
# define BOTTOMRB "./textures_xpm/bottom_right_border.xpm"
# define TOPLB "./textures_xpm/top_left_border.xpm"
# define TOPRB "./textures_xpm/top_right_border.xpm"

// /*
// *	COLLECTIBLE
// */
# define COLLECTIBLE "./textures_xpm/collectible.xpm"
# define COLLECTIBLE_TAKEN "./textures_xpm/collectible_taken.xpm"

// /*
// *	PLAYER SPRITE (2 FRAMES) UP, DOWN, LEFT, RIGHT
// */
# define PLAYER "./textures_xpm/player_u0.xpm"

# define EXIT_CLOSE "./textures_xpm/exit_close.xpm"
// # define EXIT_OPEN "../textures/exit_open.png"
//
// # define EXIT_OPEN00 "../textures/exit_open00.png"
// # define EXIT_OPEN01 "../textures/exit_open01.png"
// # define EXIT_OPEN02 "../textures/exit_open02.png"
// # define EXIT_OPEN03 "../textures/exit_open03.png"
// # define EXIT_OPEN04 "../textures/exit_open04.png"
// # define EXIT_OPEN05 "../textures/exit_open05.png"
// # define EXIT_OPEN06 "../textures/exit_open06.png"
// # define EXIT_OPEN07 "../textures/exit_open07.png"
// # define EXIT_OPEN08 "../textures/exit_open08.png"
// # define EXIT_OPEN09 "../textures/exit_open09.png"
// # define EXIT_OPEN10 "../textures/exit_open10.png"
// # define EXIT_OPEN11 "../textures/exit_open11.png"
// # define EXIT_OPEN12 "../textures/exit_open12.png"
// # define EXIT_OPEN13 "../textures/exit_open13.png"
//

typedef enum	e_bool
{
	true,
	false
}				t_bool;

// typedef enum	e_dir
// {
// 	north,
// 	south,
// 	east,
// 	west
// }				t_dir;

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

// typedef struct	s_player
// {
// 	t_pos		pos;
// 	t_dir		dir;
// 	double		move_speed;
// }				t_player;

typedef struct	s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		endian;
	int		s_line;
	// t_bool	load;
}				t_tex;

// typedef struct	s_color
// {
// 	int			r;
// 	int			g;
// 	int			b;
// 	t_bool		load;
// }				t_color;

// typedef struct	s_key
// {
// 	t_bool		up;
// 	t_bool		down;
// 	t_bool		left;
// 	t_bool		right;
// }				t_key;
// player d0  top right borderå

typedef struct	s_map
{
	char		*buff;
	char		**map;
	unsigned int height;
	unsigned int width;
}				t_map;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_win		win;
	t_tex		display;
	t_map		map;

	// t_key		key;
	//
	// t_player	player;
	//

	t_tex		grass;
	t_tex		rock;

	t_tex		right;
	t_tex		left;
	t_tex		top;
	t_tex		bottom;

	t_tex		toplb;
	t_tex		toprb;
	t_tex		bottomlb;
	t_tex		bottomrb;

	t_tex		collectible;
	t_tex		collectible_taken;

	t_tex		player;
	t_tex		exit_close;

	// t_bool		success;
	// t_bool		gameover;
	// unsigned int	nb_moves;
}				t_data;

int		get_next_line(int fd, char **line);
t_data	init_data(const char *map);
void	init_map(int fd, t_data *data);

#endif
