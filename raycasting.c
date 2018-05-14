#include "wolf.h"

void			lets_persp(int x, float dist, t_mlx *list, t_point o)
{
	int			i;

	ROOF = (float)HA / 2 - LA / (float)dist;
	FLOOR = HA - ROOF;
	WALLH = (float)FLOOR - (float)ROOF;
	o.y = 0;
	color_sky_and_floor(x, list);
	if (UP == 1)
		i = 0;
	else if (UP == -1)
		i = 1;
	else if (RIGHT == 1)
		i = 2;
	else
		i = 3;
	WALLR = (float)(list->t[i].height) / WALLH;
	o.x = get_ox(list, dist, i);
	if (ROOF < 0)
		o.y = abs(ROOF) * WALLR;
	if (dist < MAXDIST)
		ft_draw_wall(list, i, x, o);
}

float			get_ox(t_mlx *list, float dist, int i)
{
	float		collision_point;
	int			strict_value;

	collision_point = 0;
	if (UP != 0)
		collision_point = (float)(PLAYER->x + PLAYER->eye_x * dist);
	else if (RIGHT != 0)
		collision_point = (float)(PLAYER->y + PLAYER->eye_y * dist);
	strict_value = floor(collision_point);
	collision_point -= strict_value;
	return (collision_point * list->t[i].width);
}

void			get_dir(int distx, int disty, float dist, t_mlx *list)
{
	int			dist_x;
	int			dist_y;
	int			right;
	int			up;

	up = 0;
	right = 0;
	dist -= 0.01;
	dist_x = (int)(PLAYER->x + PLAYER->eye_x * dist);
	dist_y = (int)(PLAYER->y + PLAYER->eye_y * dist);
	if (dist_y > disty)
		up = 1;
	else if (dist_y < disty)
		up = -1;
	if (dist_x > distx)
		right = 1;
	else if (dist_x < distx)
		right = -1;
	if (right == 0 || up == 0)
	{
		UP = up;
		RIGHT = right;
	}
}

void			lets_search(int x, t_mlx *list, t_point o)
{
	int		distx;
	int		disty;
	float	dist;

	dist = 0;
	while (dist < MAXDIST)
	{
		distx = (float)(PLAYER->x + PLAYER->eye_x * dist);
		disty = (float)(PLAYER->y + PLAYER->eye_y * dist);
		if (distx < 0 || distx > STAGE->map_la || disty < 0
			|| disty > STAGE->map_ha || !(MAP[disty][distx]))
		{
			dist = MAXDIST;
			break;
		}
		if (MAP[disty][distx] == '1')
			break;
		dist += 0.01;
	}
	if (dist < MAXDIST)
		get_dir(distx, disty, dist, list);
	DIST = dist;
	lets_persp(x, dist, list, o);
}

void			lets_cast(t_mlx *list)
{
	int			x;
	float		ray;
	t_point		o;

	x = 0;
	o.y = 0;
	o.x = 0;
	while (x < LA)
	{
		ray = (PLAYER->a - FOV / 2.0) + ((float)x / (float)LA * FOV);
		PLAYER->eye_x = cosf(ray);
		PLAYER->eye_y = sinf(ray);
		lets_search(x, list, o);
		x++;
	}
}
