#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"

# define BUFFER_SIZE 512
# define TILE_SIZE 128

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

# define LEFT_KEY 0
# define DOWN_KEY 1
# define RIGHT_KEY 2
# define UP_KEY 13

# define ESCAPE_KEY 53
/*
*
*	TEXTURES PATH
*
*/
# define GRASS "./textures_xpm/grass.xpm"
# define ROCK "./textures_xpm/rock.xpm"
/*
*	BORDER
*/
# define RIGHTB "./textures_xpm/right_border.xpm"
# define LEFTB "./textures_xpm/left_border.xpm"
# define TOPB "./textures_xpm/top_border.xpm"
# define BOTTOMB "./textures_xpm/bottom_border.xpm"
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
# define PLAYER_UP0 "./textures_xpm/player_u0.xpm"
# define PLAYER_UP1 "./textures_xpm/player_u1.xpm"

# define PLAYER_DOWN0 "./textures_xpm/player_d0.xpm"
# define PLAYER_DOWN1 "./textures_xpm/player_d1.xpm"

# define PLAYER_RIGHT0 "./textures_xpm/player_r0.xpm"
# define PLAYER_RIGHT1 "./textures_xpm/player_r1.xpm"

# define PLAYER_LEFT0 "./textures_xpm/player_l0.xpm"
# define PLAYER_LEFT1 "./textures_xpm/player_l1.xpm"

# define EXIT_CLOSE "./textures_xpm/exit.xpm"

# define EXIT_OPEN0 "./textures_xpm/exit_open00.xpm"
# define EXIT_OPEN1 "./textures_xpm/exit_open01.xpm"
# define EXIT_OPEN2 "./textures_xpm/exit_open02.xpm"
# define EXIT_OPEN3 "./textures_xpm/exit_open03.xpm"
# define EXIT_OPEN4 "./textures_xpm/exit_open04.xpm"
# define EXIT_OPEN5 "./textures_xpm/exit_open05.xpm"
# define EXIT_OPEN6 "./textures_xpm/exit_open06.xpm"
# define EXIT_OPEN7 "./textures_xpm/exit_open07.xpm"
# define EXIT_OPEN8 "./textures_xpm/exit_open08.xpm"
# define EXIT_OPEN9 "./textures_xpm/exit_open09.xpm"
# define EXIT_OPEN10 "./textures_xpm/exit_open10.xpm"
# define EXIT_OPEN11 "./textures_xpm/exit_open11.xpm"
# define EXIT_OPEN12 "./textures_xpm/exit_open12.xpm"
# define EXIT_OPEN13 "./textures_xpm/exit_open13.xpm"

typedef enum e_bool
{
	true,
	false
}				t_bool;

typedef enum e_error
{
	INVALID_MAP_FORMAT,
	INVALID_MAP_FILE,
	INVALID_MAP,
	MALLOC_FAIL,
	MLX_ERROR,
	TEX_PATH_WRONG,
	PLAYER_DOUBLE_INITIALIZED,
	PLAYER_UNINITIALIZED,
	NO_EXIT,
	NO_COLLECTIBLES
}				t_error;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef enum e_dir
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}				t_dir;

typedef struct s_win
{
	int			height;
	int			width;
}				t_win;

typedef struct s_tex
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

typedef struct s_player
{
	t_pos		pos;
	t_dir		dir;
	t_tex		sprite_down[2];
	t_tex		sprite_up[2];
	t_tex		sprite_right[2];
	t_tex		sprite_left[2];
	int			frame;
}				t_player;

typedef struct s_map
{
	int				fd;
	char			*buff;
	char			**map;
	unsigned int	height;
	unsigned int	width;
}					t_map;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_bool			win_load;
	t_win			win;
	t_tex			display;
	t_bool			display_load;

	t_map			map;
	t_bool			map_load;
	t_player		player;
	t_bool			player_load;
	t_bool			exit_load;

	t_tex			grass;
	t_tex			rock;
	t_tex			right;
	t_tex			left;
	t_tex			top;
	t_tex			bottom;
	t_tex			toplb;
	t_tex			toprb;
	t_tex			bottomlb;
	t_tex			bottomrb;
	t_tex			collectible;
	t_tex			collectible_taken;
	t_tex			exit_close;
	t_tex			exit_open[14];

	unsigned int	nb_moves;
	unsigned int	nb_collectibles;
	unsigned int	nb_collectibles_taken;
	int				door_frame;
}					t_data;

int		get_next_line(int fd, char **line);
t_data	init_data(const char *map);
void	init_map(t_data *d, char const *map);
void	check_map_file(t_data *d, const char *map);
void	create_map(t_data *d);
void	malloc_map(t_data *d);
void	fill_map(t_data *d);
void	check_map_validity(t_data *d);
void	init_player(t_data *d, unsigned int y, unsigned int x);
void	init_sprites_and_tiles(t_data *d);

int		update(int key, t_data *d);

int		draw(t_data *d);
void	draw_tile(t_data *d, t_tex *tex, int y, int x, int yb, int xb);
void	draw_sprite(t_data *d, t_tex *tex, int y, int x, int yb, int xb);


void	handle_error(t_data *d, int error);
void	free_map(char **map);
void	free_tex(t_data *d);
int		exit_game(t_data *d);


/*
* BONUS FUNCTIONS
*/
void	handle_frame(t_data *d);
void	display_nb_move(t_data *d);

#endif
