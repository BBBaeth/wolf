
#include "wolf.h"

void	color_sky_and_floor(int x, t_mlx *list)
{
	int		color_sky;
	int		color_floor;
	int		pos;

	color_sky = -1;
	color_floor = FLOOR - 1;
	if (WALLH < HA)
	{
		while (++color_sky <= FLOOR)
		{
			pos = (x * BPP) + (color_sky * S_L);
			if (x < LA && color_sky < HA && x >= 0 && color_sky >= 0)
				{
					IMG_DATA[pos + 0] = (char)250;
					IMG_DATA[pos + 1] = (char)120;
					IMG_DATA[pos + 2] = (char)120;
					IMG_DATA[pos + 3] = (char)((0 + color_sky / 2) % 255);
				}
		}
		while (++color_floor < HA)
		{
			pos = (x * BPP) + (color_floor * S_L);
			if (x < LA && color_floor < HA && x >= 0 && color_floor >= 0)
				{
					IMG_DATA[pos + 0] = (char)280 - color_floor / 4;
					IMG_DATA[pos + 1] = (char)100;
					IMG_DATA[pos + 2] = (char)160;
					IMG_DATA[pos + 3] = (char)(360 - color_floor / 3);
				}
		}
	}
}

void	ft_draw_wall(t_mlx *list, int i, int x, t_point o)
{
	int		pos;
	int		y;

	y = ROOF;
	while (y < FLOOR)
	{
		if (y > ROOF && y < FLOOR)
		{
			pos = (x * BPP) + (y * S_L);
			if (x < LA && y < HA && x >= 0 && y >= 0)
			{
				o.y += WALLR;
				if (o.y > (float)(list->t[i].height))
						o.y = 0;
				attribute_text_color_to_image(list, i, pos, o);
				IMG_DATA[pos + 3] += (char)(0 + ((int)DIST * 4 % 200));
			}
		}
		y++;
	}
}
