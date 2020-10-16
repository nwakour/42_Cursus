#include "cub3d.h"

void	init_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->width = 5;
	player->height = 5;
	player->turn = 0;
	player->walk = 0;
	player->rotation = PI / 2;
	player->walkspeed = 20;
	player->turnspeed = 20 * (PI / 180);
}

void player_move(t_all *all)
{
	float steps;
	float new_x;
	float new_y;

	all->player.rotation += all->player.turn * all->player.turnspeed;
	steps = all->player.walk * all->player.walkspeed;
	new_x = all->player.x + cos(all->player.rotation) * steps;
	new_y = all->player.y + sin(all->player.rotation) * steps;
	if (!ft_collision(all, new_x, new_y))
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
	all->player.walk = 0;
	all->player.turn = 0;
}

void draw_player(t_all *all)
{
	player_move(all);
	all->draw.start_x = all->player.x * MINI_MAP;
	all->draw.start_y = all->player.y * MINI_MAP;
	all->draw.width = all->player.width * MINI_MAP;
	all->draw.height = all->player.height * MINI_MAP;
	drawblock(all->mlx.img_data, all->draw, 0x6a0dad);
}