/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_exporter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:51 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/30 16:18:07 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		create_file(t_all *all, char *file_name)
{
	int	fd;

	if (!((fd = open(file_name, O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		perror("Error\nFailed creating .bmp\n");
		free_all(all, ERROR);
	}
	return (fd);
}

static void		create_header(t_all *all, t_bmp *bmp)
{
	bmp->byte_type[0] = 0x42;
	bmp->byte_type[1] = 0x4D;
	bmp->byte_size = (all->info.window_width *
					all->info.window_height * 4) + 54;
	bmp->byte_reserved = 0x00000000;
	bmp->byte_offset = 0x36;
	bmp->header_size = 40;
	bmp->image_width = all->info.window_width;
	bmp->image_height = -all->info.window_height;
	bmp->color_planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 0;
	bmp->image_size = (all->info.window_width * all->info.window_height * 4);
	bmp->bits_xpels_per_meter = 2835;
	bmp->bits_xpels_per_meter = 2835;
	bmp->total_colors = 0;
	bmp->important_colors = 0;
}

static void		write_header(int fd, t_bmp bmp)
{
	int			r;

	r = 0;
	r = write(fd, &bmp.byte_type, 2);
	r = write(fd, &bmp.byte_size, 4);
	r = write(fd, &bmp.byte_reserved, 4);
	r = write(fd, &bmp.byte_offset, 4);
	r = write(fd, &bmp.header_size, 4);
	r = write(fd, &bmp.image_width, 4);
	r = write(fd, &bmp.image_height, 4);
	r = write(fd, &bmp.color_planes, 2);
	r = write(fd, &bmp.bits_per_pixel, 2);
	r = write(fd, &bmp.compression, 4);
	r = write(fd, &bmp.image_size, 4);
	r = write(fd, &bmp.bits_xpels_per_meter, 4);
	r = write(fd, &bmp.bits_ypels_per_meter, 4);
	r = write(fd, &bmp.total_colors, 4);
	r = write(fd, &bmp.important_colors, 4);
}

static void		write_file(t_all *all, int fd, int imagesize)
{
	char		*pixel_array;
	int			i;
	int			j;

	if (!(pixel_array = malloc(sizeof(char) * imagesize)))
		free_all(all, ERROR);
	i = 0;
	j = 0;
	imagesize /= 4;
	while (i < imagesize)
	{
		pixel_array[j++] = all->mlx.img_data[i] & 255;
		pixel_array[j++] = (all->mlx.img_data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (all->mlx.img_data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(fd, pixel_array, imagesize *= 4);
	free(pixel_array);
}

void			bmp_exporter(t_all *all, char *file_name)
{
	t_bmp		bmp;
	int			fd;

	ft_bzero(&bmp, sizeof(t_bmp));
	fd = create_file(all, file_name);
	create_header(all, &bmp);
	write_header(fd, bmp);
	write_file(all, fd, bmp.image_size);
	close(fd);
}
