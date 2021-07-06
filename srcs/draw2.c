#include "../includes/so_long.h"

void	draw_tile(t_data *d, t_tex *tex, int y, int x, int yb, int xb)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)x * ((float)tex->width / (float)TILE_SIZE);
	y_scale = (float)y * ((float)tex->height / (float)TILE_SIZE);
	d->display.addr[((x + (xb * TILE_SIZE)) * d->display.bpp >> 3)
		+ ((y + (yb * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)];
	d->display.addr[((x + (xb * TILE_SIZE)) * d->display.bpp >> 3) + 1
		+ ((y + (yb * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)];
	d->display.addr[((x + (xb * TILE_SIZE)) * d->display.bpp >> 3) + 2
		+ ((y + (yb * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)];
}

void	draw_sprite(t_data *d, t_tex *tex, int y, int x, int yb, int xb)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)x * ((float)tex->width / (float)TILE_SIZE);
	y_scale = (float)y * ((float)tex->height / (float)TILE_SIZE);
	if (tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)] == 0
		&& tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)]
		== 0
		&& tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)]
		== 0)
		return ;
	d->display.addr[((x + (xb * TILE_SIZE)) * d->display.bpp >> 3)
		+ ((y + (yb * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)];
	d->display.addr[((x + (xb * TILE_SIZE)) * d->display.bpp >> 3) + 1
		+ ((y + (yb * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)];
	d->display.addr[((x + (xb * TILE_SIZE)) * d->display.bpp >> 3) + 2
		+ ((y + (yb * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)];
}
