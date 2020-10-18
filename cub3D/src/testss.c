static void	render_sprite(t_all *all, t_sprite *sprite, t_player *player)
{
	int		spt_size;
	int		x_ofst;
	int		y_ofst;
	float	sprite_dir;

	float dx = sprite->x + 0.5 - player->x;
	float dy = sprite->y + 0.5 - player->y;
	sprite->dist = sqrt(dx*dx + dy*dy);
	float s_angle = atan2(dy, dx) - player->rotation;
	float viewdist = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	spt_size = viewdist / (cos(s_angle) * sprite->dist);
	float x = tan(s_angle) * viewdist;
	float dbx = sprite->x - player->x;
	float dby = sprite->y - player->y;
	float blockdist = dbx*dbx + dby*dby;
}


void		init_sprite(t_info *info, int x, int y)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	info->num_sprite++;
	if (!(sprite = malloc(sizeof(*sprite))))
		error_global(info);
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	sprite->texture = TEX_S;
	if (info->sprite)
		sprite->next = info->sprite;
	else
		sprite->next = NULL;
	info->sprite = sprite;
}

static void	sort_sprite(t_sprite **begin)
{
	t_sprite	*sp;
	t_sprite	*bef;
	t_sprite	*nxt;

	if (*begin)
	{
		sp = *begin;
		bef = 0;
		while (sp->next)
		{
			nxt = sp->next;
			if (sp->dist < nxt->dist)
			{
				sp->next = nxt->next;
				nxt->next = sp;
				if (bef)
					bef->next = nxt;
				else
					*begin = nxt;
				sp = *begin;
			}
			bef = sp;
			sp = sp->next;
		}
	}
}

static void	render_sprite_2(t_info *info, int spt_size, int x_ofst, int y_ofst)
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < spt_size)
	{
		if (x_ofst + i < 0 || x_ofst + i > info->res_x)
			continue ;
		if (info->ray[x_ofst + i].dist <= info->sprite->dist)
			continue ;
		j = -1;
		while (++j < spt_size)
		{
			if (y_ofst + j < 0 || y_ofst + j >= info->res_y)
				continue ;
			color = info->tex[TEX_S].tex[i * TEXTURE_SIZE / spt_size]
			[j * TEXTURE_SIZE / spt_size];
			if (color != 0)
				info->img.data[(y_ofst + j) * info->res_x +
				(info->res_x + x_ofst + i)] = color;
		}
	}
}

static void	render_sprite(t_info *info, t_sprite *sprite, t_player *player)
{
	int		spt_size;
	int		x_ofst;
	int		y_ofst;
	float	sprite_dir;

	sprite_dir = atan2(sprite->y - player->y, sprite->x - player->x);
	while (sprite_dir - player->rotate_angle > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - player->rotate_angle < -M_PI)
		sprite_dir += 2 * M_PI;
	if (info->res_y > info->res_x)
		spt_size = info->res_y / sprite->dist;
	else
		spt_size = info->res_x / sprite->dist;
	x_ofst = (sprite_dir - player->rotate_angle) * info->res_x / info->fov +
	(info->res_x / 2 - spt_size / 2);
	y_ofst = info->res_y / 2 - spt_size / 2;
	render_sprite_2(info, spt_size, x_ofst, y_ofst);
}

void		generete_sprite(t_info *info, t_player *player)
{
	t_sprite *beg;

	beg = info->sprite;
	while (beg)
	{
		beg->dist = dist_point(player->x, player->y, beg->x, beg->y);
		beg = beg->next;
	}
	sort_sprite(&info->sprite);
	beg = info->sprite;
	while (info->sprite)
	{
		render_sprite(info, info->sprite, player);
		info->sprite = info->sprite->next;
	}
	info->sprite = beg;
}