/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:58:07 by ceugene           #+#    #+#             */
/*   Updated: 2018/05/07 11:58:10 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
					IMG_DATA[pos + 0] = (char)100;
					IMG_DATA[pos + 1] = (char)100;
					IMG_DATA[pos + 2] = (char)160;
					IMG_DATA[pos + 3] = (char)200;
				}
		}
	}
}

void	ft_draw_item(t_mlx *list, int x, t_point o)
{
	int		pos;
	int		i;
	int		y;
	int		distx;
	int		disty;

	i = 4;
	while (list->encountered_items > 0)
	{
		o.x = get_ox(list, DIST, i);
		y = FLOOR * 1.5 - list->t[i].height;
		DIST -= 0.01;
		o.y = 0;
		distx = (float)(PLAYER->x + PLAYER->eye_x * DIST);
		disty = (float)(PLAYER->y + PLAYER->eye_y * DIST);
		if (MAP[disty][distx] != ' ' && MAP[disty][distx] != '1' && MAP[disty][distx] != '2')
		{
			MAP[disty][distx] = 2;
			while (y < HA)
			{
				pos = (x * BPP) + (y * S_L);
				if (x < LA && y < HA && x >= 0 && y >= 0)
				{
					o.y += 1;
					if (o.y > (float)(list->t[i].height))
						break;
					if (o.x > (float)(list->t[i].width))
						break;
					attribute_text_color_to_image(list, i, pos, o);
				}
				y++;
			}
			list->encountered_items--;
			DIST -= 1;
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
