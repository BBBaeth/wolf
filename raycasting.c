#include "wolf.h"

void			lets_persp(int x, float dist, t_mlx *list, t_point o)
{
	int			y;
	int			color_sky;
	int			color_floor;
	int			pos;
	int			colr;
	int			i;

	ROOF = (float)HA / 2 - LA / (float)dist;
	FLOOR = HA - ROOF;
	WALLH = (float)FLOOR - (float)ROOF;
	y = ROOF;
	o.y = 0;
	color_sky = 0;
	color_floor = FLOOR;
	while (color_sky <= ROOF)
	{
		pos = (x * BPP) + (color_sky * S_L);
		if (x < LA && y < HA && x >= 0 && y >= 0)
			{
				IMG_DATA[pos + 0] = (char)250;
				IMG_DATA[pos + 1] = (char)120;
				IMG_DATA[pos + 2] = (char)120;
				IMG_DATA[pos + 3] = (char)100;
			}
		color_sky++;
	}
	while (color_floor <= HA)
	{
		pos = (x * BPP) + (color_floor * S_L);
		if (x < LA && y < HA && x >= 0 && y >= 0)
			{
				IMG_DATA[pos + 0] = (char)100;
				IMG_DATA[pos + 1] = (char)100;
				IMG_DATA[pos + 2] = (char)160;
				IMG_DATA[pos + 3] = (char)100;
			}
		color_floor++;
	}
	colr = 200;
	if (UP == 1)
		i = 1;
	else if (UP == -1)
		i = 0;
	else if (RIGHT == 1)
		i = 2;
	else
		i = 3;
	WALLR = (float)(list->t[i]->height) / WALLH;
	o.x = get_ox(list, dist, i);
	if (ROOF < 0)
		o.y = abs(ROOF) * WALLR;
	while (y < FLOOR)
	{
		if (y > ROOF && y < FLOOR && dist < 40)
		{
			pos = (x * BPP) + (y * S_L);
			if (x < LA && y < HA && x >= 0 && y >= 0)
			{
				IMG_DATA[pos + 0] = (char)colr - (float)(3 * dist);
				IMG_DATA[pos + 1] = (char)colr - (float)(3 * dist);
				IMG_DATA[pos + 2] = (char)190 - (float)(3 * dist);
				IMG_DATA[pos + 3] = (char)0 + (int)((float)(4 * dist)) % 1000;
			}
			if (x < LA && y < HA && x >= 0 && y >= 0)
			{
				o.y += WALLR;
				if (o.y > (float)(list->t[i]->height))
						o.y = 0;
				attribute_text_color_to_image(list, i, pos, o);
			}
		}
		y++;
	}
}

int			get_ox(t_mlx *list, float dist, int i)
{
	float		collision_point;
	int			strict_value;

	collision_point = 0;
	if (UP == 1)
		collision_point = (float)(PLAYER->x + PLAYER->eye_x * dist);
	if (RIGHT == 1)
		collision_point = (float)(PLAYER->y + PLAYER->eye_y * dist);
	strict_value = floor(collision_point);
	collision_point -= strict_value;
	return ((float)collision_point * (float)list->t[i]->width);
}

void			get_dir(int distx, int disty, float dist, t_mlx *list)
{
	int			dist_x;
	int			dist_y;
	int			right;
	int			up;

	up = 0;
	right = 0;
	dist -= 0.03;
	dist_x = (int)(PLAYER->x + PLAYER->eye_x * dist);
	dist_y = (int)(PLAYER->y + PLAYER->eye_y * dist);
	if (dist_y > disty)
		up = 1;
	if (dist_y < disty)
		up = -1;
	if (dist_x > distx)
		right = 1;
	if (dist_x < distx)
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
	while (dist < 40)
	{
		distx = (int)(PLAYER->x + PLAYER->eye_x * dist);
		disty = (int)(PLAYER->y + PLAYER->eye_y * dist);
		if (distx < 0 || distx > STAGE->map_la || disty < 0
			|| disty > STAGE->map_ha)
		{
			dist = 40;
			break;
		}
		if (MAP[disty][distx] == '1')
			break;
		dist += 0.03;
	}
	if (dist < 40)
		get_dir(distx, disty, dist, list);
	lets_persp(x, dist, list, o);
}

void			lets_cast(t_mlx *list)
{
	int			x;
	float		ray;
	t_point		o;

	x = 0;
	o.y = 0;
	while (x < LA)
	{
		ray = (PLAYER->a - FOV / 2.0) + ((float)x / (float)LA * FOV);
		PLAYER->eye_x = cosf(ray);
		PLAYER->eye_y = sinf(ray);
		lets_search(x, list, o);
		x++;
	}
}
