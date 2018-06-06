/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:11:32 by ceugene           #+#    #+#             */
/*   Updated: 2018/05/26 15:18:39 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		color_minimap(t_mlx *list, int **tab)
{
	int		select;
	int		count;

	count = 0;
	while (count < 10)
	{
		select = 0;
		while (select < 10)
		{
			color_squares(list, 10 * select, 10 * count, tab[count][select]);
			select++;
		}
		count++;
	}
}

void		fill_tab(t_mlx *list, int **tab)
{
	int		posx;
	int		posy;
	int		count;
	int		select;

	count = 0;
	select = 0;
	posy = floor(PLAYER->y) - 2;
	while (count < 10)
	{
		select = 0;
		posx = floor(PLAYER->x) - 2;
		while (select < 10)
		{
			if (posy < 0 || posy > STAGE->map_ha || posx < 0 || posx > STAGE->map_la)
				tab[count][select] = 2;
			else if (MAP[posy][posx] == '1')
				tab[count][select] = 1;
			else if (posy == floor(PLAYER->y) && posx == floor(PLAYER->x))
				tab[count][select] = 3;
			else
				tab[count][select] = 0;
			select++;
			posx++;
		}
		count++;
		posy++;
	}
	color_minimap(list, tab);
}

void		minimap_table(t_mlx *list)
{
	int		**tab;
	int		count;
	int		select;

	count = -1;
	if (!(tab = malloc(sizeof(int *) * 10)))
		ft_fail("Error: Unable to allocate memory.", list);
	while (++count < 10)
	{
		if (!(tab[count] = malloc(sizeof(int) * 10)))
			ft_fail("Error: Unable to allocate memory.", list);
	}
	count = 0;
	while (count < 10)
	{
		select = 0;
		while (select < 10)
		{
			tab[count][select] = 0;
			select++;
		}
		count++;
	}
	list->minimap = tab;
}

void		draw_square(t_mlx *list)
{
	int		pos;
	int		x;
	int		y;

	y = 2;
	while (y < list->minimap_h - 2)
	{
		x = 0;
		while (x < list->minimap_l)
		{
			if (x >= 2 && x <= list->minimap_l - 2)
			{
				pos = (x * BPP) + (y * S_L);
				IMG_DATA[pos + 0] = (char)50;
				IMG_DATA[pos + 1] = (char)50;
				IMG_DATA[pos + 2] = (char)50;
				IMG_DATA[pos + 3] = (char)0;
			}
			x++;
		}
		y++;
	}
	fill_tab(list, list->minimap);
}
