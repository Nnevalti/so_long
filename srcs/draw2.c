#include "../includes/so_long.h"

void	draw_tile(t_data *d, t_tex *tex)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)d->draw.x_s * ((float)tex->width / (float)TILE_SIZE);
	y_scale = (float)d->draw.y_s * ((float)tex->height / (float)TILE_SIZE);
	d->display.addr[((d->draw.x_s + (d->draw.x_t * TILE_SIZE))
			* d->display.bpp >> 3)
		+ ((d->draw.y_s + (d->draw.y_t * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * TILE_SIZE))
			* d->display.bpp >> 3) + 1
		+ ((d->draw.y_s + (d->draw.y_t * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * TILE_SIZE))
			* d->display.bpp >> 3) + 2
		+ ((d->draw.y_s + (d->draw.y_t * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)];
}

void	draw_sprite(t_data *d, t_tex *tex)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)d->draw.x_s * ((float)tex->width / (float)TILE_SIZE);
	y_scale = (float)d->draw.y_s * ((float)tex->height / (float)TILE_SIZE);
	if (tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)] == 0
		&& tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)]
		== 0
		&& tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)]
		== 0)
		return ;
	d->display.addr[((d->draw.x_s + (d->draw.x_t * TILE_SIZE))
			* d->display.bpp >> 3)
		+ ((d->draw.y_s + (d->draw.y_t * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * TILE_SIZE))
			* d->display.bpp >> 3) + 1
		+ ((d->draw.y_s + (d->draw.y_t * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * TILE_SIZE))
			* d->display.bpp >> 3) + 2
		+ ((d->draw.y_s + (d->draw.y_t * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)];
}

void	draw_player_sprite(t_data *d, t_tex *tex)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)d->draw.x_s * ((float)tex->width / (float)TILE_SIZE);
	y_scale = (float)d->draw.y_s * ((float)tex->height / (float)TILE_SIZE);
	if (tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)] == 0
		&& tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)]
		== 0
		&& tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)]
		== 0)
		return ;
	d->display.addr[((d->draw.x_s + (d->player.pos.x * TILE_SIZE))
			* d->display.bpp >> 3)
		+ ((d->draw.y_s + (d->player.pos.y * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + (y_scale * tex->s_line)];
	d->display.addr[((d->draw.x_s + (d->player.pos.x * TILE_SIZE))
			* d->display.bpp >> 3) + 1
		+ ((d->draw.y_s + (d->player.pos.y * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 1 + (y_scale * tex->s_line)];
	d->display.addr[((d->draw.x_s + (d->player.pos.x * TILE_SIZE))
			* d->display.bpp >> 3) + 2
		+ ((d->draw.y_s + (d->player.pos.y * TILE_SIZE)) * d->display.s_line)]
		= tex->addr[(x_scale * tex->bpp >> 3) + 2 + (y_scale * tex->s_line)];
}
