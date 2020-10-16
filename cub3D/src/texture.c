#include "cub3d.h"

int	take_texture(t_mlx *mlx, t_tex *tex)
{
	if (!(tex->tex_ptr = mlx_xpm_file_to_image(mlx->mlx_p,
		tex->path, &tex->width, &tex->height)))
		return (-1);
	if (!(tex->img_data = (int *)mlx_get_data_addr(tex->tex_ptr,
		&tex->bits, &tex->size, &tex->endian)))
		return (-1);
	return (1);
}

/*int put_texture(t_all *all, int i, int j, int wall_bot)
{
	int y;
	int x;

	x = i;
	y = 0;
	while (j < wall_bot)
	{
		if (x > TILE_SIZE)
			x = 0;
		if (y > TILE_SIZE)
			y = 0;
		if (all->ray[i].ray_cord == 0)
			all->mlx.img_data[WINDOW_WIDTH * j + i] = all->tex[TEX_NO].tex[x][y];
		else if (all->ray[i].ray_cord == 1)
			all->mlx.img_data[WINDOW_WIDTH * j + i] = 0x450000;
		else if (all->ray[i].ray_cord == 2)
			all->mlx.img_data[WINDOW_WIDTH * j + i] = 0x004500;
		else if (all->ray[i].ray_cord == 3)
			all->mlx.img_data[WINDOW_WIDTH * j + i] = 0x000045;
		j++;
		y++;
	}
	return j;
}
*/

void		init_textute(t_all *all)
{
 	take_texture(&all->mlx, &all->tex[TEX_NO]);
	take_texture(&all->mlx, &all->tex[TEX_SO]);
	take_texture(&all->mlx, &all->tex[TEX_WE]);
	take_texture(&all->mlx, &all->tex[TEX_EA]);
	take_texture(&all->mlx, &all->tex[TEX_S]);
}