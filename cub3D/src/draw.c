#include "cub3d.h"

void init_draw(t_draw *draw)
{
	draw->start_x = 0;
	draw->start_y = 0;
	draw->end_x = 0;
	draw->end_y = 0;
	draw->width = 0;
	draw->height = 0;
	draw->color = 0;
}

void drawline(int *img_data, t_draw draw)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int er2;

	draw.start_x *= MINI_MAP;
	draw.start_y *= MINI_MAP;
	draw.end_x *= MINI_MAP;
	draw.end_y *= MINI_MAP;
	dx =  abs(draw.end_x - draw.start_x);
    sx = draw.start_x < draw.end_x ? 1 : -1;
    dy = -abs(draw.end_y - draw.start_y);
    sy = draw.start_y < draw.end_y ? 1 : -1;
    err = dx+dy;
    while ((draw.start_x != draw.end_x) || (draw.start_y != draw.end_y))
	{
        img_data[draw.start_y * WINDOW_WIDTH + draw.start_x] = draw.color;
        er2 = 2*err;
        if (er2 >= dy)
		{
            err += dy;
            draw.start_x += sx;
		}
        if (er2 <= dx)
		{
            err += dx;
            draw.start_y += sy;
		}
		if (draw.start_x!= draw.end_x && draw.start_y!= draw.end_y)
			img_data[draw.start_y * WINDOW_WIDTH + draw.start_x] = draw.color;
	}
}

void drawblock(int *img_data, t_draw draw, int color)
{
	int end;

	end = draw.start_x + draw.width;
	draw.end_y = draw.start_y + draw.height;
	draw.color = color;
	while (draw.start_x < end)
	{
		draw.end_x = draw.start_x;
		drawline(img_data, draw);
		draw.start_x++;
	}
}

void projection_3d(t_all *all)
{
	int i;
	int j;
	int x;
	int y;
	float prep_dist;
	float dist_y;
	float wall_height;
	int wall_s_height;
	int wall_top;
	int wall_bot;

	i = -1;
	while (++i < NUM_RAYS)
	{
		prep_dist = all->ray[i].dist * cos(all->ray[i].ray_angle - all->player.rotation);
		dist_y = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		wall_height = (TILE_SIZE / prep_dist) * dist_y;
		wall_s_height = (int)wall_height;
		wall_top = (WINDOW_HEIGHT / 2) - (wall_s_height / 2);
		wall_top = wall_top < 0 ? 0 : wall_top;
		wall_bot = (WINDOW_HEIGHT / 2) + (wall_s_height / 2);
		wall_bot = wall_bot > WINDOW_HEIGHT ? WINDOW_HEIGHT : wall_bot;
		j = -1;
		while (++j < wall_top)
			all->mlx.img_data[WINDOW_WIDTH * j + i] = 0x333333;
		if (all->ray[i].hit_ver)
			x = (int)all->ray[i].wall_y % TILE_SIZE;
		else
			x = (int)all->ray[i].wall_x % TILE_SIZE;
		while (j < wall_bot)
		{
			int dist_from_top = j + (wall_s_height / 2) - (WINDOW_HEIGHT / 2);
			y = dist_from_top * ((float)TILE_SIZE / wall_s_height);
			all->mlx.img_data[j * WINDOW_WIDTH + i] =
			all->tex[all->ray[i].ray_cord].img_data[(TILE_SIZE * y + x)];
			j++;
		}

		while (j < WINDOW_HEIGHT)
		{
			all->mlx.img_data[WINDOW_WIDTH * j + i] = 0x777777;
			j++;
		}
	}
}