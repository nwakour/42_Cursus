#include "cub3d.h"

int key_press_hook(int c, t_all *all)
{
	if (c == UP_KEY) //up
		all->player.walk = +1;
	else if (c == DOWN_KEY) //down
		all->player.walk = -1;
	else if (c == RIGHT_KEY) //right
		all->player.turn = +1;
	else if (c == LEFT_KEY) //left
		all->player.turn = -1;
	return 0;
}

int key_hook(int key, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if ((key >= 0 && key <= 2) || key == 13)
	{
		key_press_hook(key, all);
		update_all(all);
		render_all(all);
	}
	if (key == ESP_KEY)
	{
		mlx_destroy_window(all->mlx.mlx_p, all->mlx.win_p);
		exit(0);
	}
	return 0;
}