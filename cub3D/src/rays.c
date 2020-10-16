#include "cub3d.h"

int ray_coordinate(float ray_angle, int hit_ver)
{

	float angle;

	angle = rad_to_angle(ray_angle);
	if ((angle < 45) || (angle >= 45 && angle < 90))
	{
		if (hit_ver)
			return NO;
		else
			return EA;
	}
	else if ((angle >= 90 && angle < 135) || (angle >= 135 && angle < 180))
	{
		if (hit_ver)
			return SO;
		else
			return EA;
	}
	else if ((angle >= 180 && angle < 225) || (angle >= 225 && angle < 270))
	{
		if (hit_ver)
			return SO;
		else
			return WE;
	}
	else
	{
		if (hit_ver)
			return NO;
		else
			return WE;
	}
}

void	cast_ray(t_all *all, float ray_angle, int ray_num)
{
	int ray_is_up;
	int ray_is_down;
	int ray_is_right;
	int ray_is_left;

	float inter_x;
	float inter_y;
	float step_x;
	float step_y;

	int hoz_wall;
	float hoz_wall_x;
	float hoz_wall_y;
	//int hoz_wall_cont;

	float next_hoz_x;
	float next_hoz_y;

	int vert_wall;
	float vert_wall_x;
	float vert_wall_y;
	//int vert_wall_cont;

	float next_vert_x;
	float next_vert_y;

	float check_x;
	float check_y;

	float hoz_dist;
	float vert_dist;

	ray_angle = normalize_angle(ray_angle);
	ray_is_down = ray_angle > 0 && ray_angle < PI;
	ray_is_up = !ray_is_down;
	ray_is_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	ray_is_left = !ray_is_right;

	hoz_wall = 0;
	hoz_wall_x = 0;
	hoz_wall_y = 0;
	//hoz_wall_cont = 0;

	inter_y = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
	inter_y += ray_is_down ? TILE_SIZE : 0;

	inter_x = all->player.x + (inter_y - all->player.y) / tan(ray_angle);

	step_y = TILE_SIZE;
	step_y *= ray_is_up ? -1 : 1;

	step_x = TILE_SIZE / tan(ray_angle);
	step_x *= (ray_is_left && step_x > 0) ? -1 : 1;
	step_x *= (ray_is_right && step_x < 0) ? -1 : 1;

	next_hoz_x = inter_x;
	next_hoz_y = inter_y;

	while (next_hoz_x >= 0 && next_hoz_x <= WINDOW_WIDTH && next_hoz_y >= 0 && next_hoz_y <= WINDOW_HEIGHT)
	{
		check_x = next_hoz_x;
		check_y = next_hoz_y + (ray_is_up ? -1 : 0);

		if (ft_collision(all, check_x, check_y))
		{
			hoz_wall_x = next_hoz_x;
			hoz_wall_y = next_hoz_y;
			hoz_wall = 1;
			break;
		}
		else
		{
			next_hoz_x += step_x;
			next_hoz_y += step_y;
		}
	}

	vert_wall = 0;
	vert_wall_x = 0;
	vert_wall_y = 0;
	//vert_wall_cont = 0;

	inter_x = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	inter_x += ray_is_right ? TILE_SIZE : 0;

	inter_y = all->player.y + (inter_x - all->player.x) * tan(ray_angle);

	step_x = TILE_SIZE;
	step_x *= ray_is_left ? -1 : 1;

	step_y = TILE_SIZE * tan(ray_angle);
	step_y *= (ray_is_up && step_y > 0) ? -1 : 1;
	step_y *= (ray_is_down && step_y < 0) ? -1 : 1;

	next_vert_x = inter_x;
	next_vert_y = inter_y;

	while (next_vert_x >= 0 && next_vert_x <= WINDOW_WIDTH && next_vert_y >= 0 && next_vert_y <= WINDOW_HEIGHT)
	{
		check_x = next_vert_x + (ray_is_left ? -1 : 0);
		check_y = next_vert_y;

		if (ft_collision(all, check_x, check_y))
		{
			vert_wall_x = next_vert_x;
			vert_wall_y = next_vert_y;
			vert_wall = 1;
			break;
		}
		else
		{
			next_vert_x += step_x;
			next_vert_y += step_y;
		}
	}

	hoz_dist = hoz_wall ? dist_points(all->player.x, all->player.y, hoz_wall_x, hoz_wall_y) : INT_MAX;
	vert_dist = vert_wall ? dist_points(all->player.x, all->player.y, vert_wall_x, vert_wall_y) : INT_MAX;
	if (vert_dist < hoz_dist)
	{
		all->ray[ray_num].dist = vert_dist;
		all->ray[ray_num].wall_x = vert_wall_x;
		all->ray[ray_num].wall_y = vert_wall_y;
		all->ray[ray_num].hit_ver = 1;
	}
	else
	{
		all->ray[ray_num].dist = hoz_dist;
		all->ray[ray_num].wall_x = hoz_wall_x;
		all->ray[ray_num].wall_y = hoz_wall_y;
		all->ray[ray_num].hit_ver = 0;
	}
	all->ray[ray_num].ray_angle = ray_angle;
	all->ray[ray_num].ray_down = ray_is_down;
	all->ray[ray_num].ray_up = ray_is_up;
	all->ray[ray_num].ray_left = ray_is_left;
	all->ray[ray_num].ray_right = ray_is_right;
	all->ray[ray_num].ray_cord = ray_coordinate(ray_angle, all->ray[ray_num].hit_ver);

		
	
}

void	cast_all_rays(t_all *all)
{
	float ray_angle;
	float dist;
	int i;

	i = 0;
	dist = (WINDOW_WIDTH / 2 ) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		ray_angle = all->player.rotation + atan((i - (NUM_RAYS / 2)) / dist);

		cast_ray(all, ray_angle, i);
		i++;
	}
}

void render_rays(t_all *all)
{
	int i;

	i = -1;
	all->draw.start_x = all->player.x;
	all->draw.start_y = all->player.y;
	all->draw.color = 0xFF0000;
	while (++i < NUM_RAYS)
	{
		all->draw.end_x = all->ray[i].wall_x;
		all->draw.end_y = all->ray[i].wall_y;
		drawline(all->mlx.img_data, all->draw);
	}
}
