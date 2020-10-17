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

void		init_textute(t_all *all)
{
 	take_texture(&all->mlx, &all->tex[TEX_NO]);
	take_texture(&all->mlx, &all->tex[TEX_SO]);
	take_texture(&all->mlx, &all->tex[TEX_WE]);
	take_texture(&all->mlx, &all->tex[TEX_EA]);
	take_texture(&all->mlx, &all->tex[TEX_S]);
}