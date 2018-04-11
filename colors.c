#include "wolf.h"

void	attribute_text_color_to_image(t_mlx *list, int i, int pos, t_point o)
{
	IMG_DATA[pos + 0] = (char)list->t[i]->data[(int)o.x * list->t[i]->bpp
		+ (int)o.y * list->t[i]->s_l];
	IMG_DATA[pos + 1] = (char)list->t[i]->data[(int)o.x * list->t[i]->bpp
		+ (int)o.y * list->t[i]->s_l + 1];
	IMG_DATA[pos + 2] = (char)list->t[i]->data[(int)o.x * list->t[i]->bpp
		+ (int)o.y * list->t[i]->s_l + 2];
}

void	roof_to_floor(t_mlx *list)
{
	int		x;
	int		y;
	int		pos;

	y = 0;
	while (y < HA)
	{
		x = 0;
		while (x < LA)
		{
			pos = (x * BPP) + (y *S_L);
			if (x < LA && y < HA && x >= 0 && y >= 0)
			{
				IMG_DATA[pos + 0] = (char)55;
				IMG_DATA[pos + 1] = (char)55;
				IMG_DATA[pos + 2] = (char)95;
				IMG_DATA[pos + 3] = (char)255 - y / 4;
				x++;
			}
		}
		y++;
	}
}

void	floor_to_roof(t_mlx *list)
{
	int		x;
	int		y;
	int		pos;

	y = 0;
	while (y < HA)
	{
		x = 0;
		while (x < LA)
		{
			pos = (x * BPP) + (y *S_L);
			IMG_DATA[pos + 0] = (char)100;
			IMG_DATA[pos + 1] = (char)100;
			IMG_DATA[pos + 2] = (char)100 + y % 4;
			x++;
		}
		y++;
	}
	roof_to_floor(list);
}
