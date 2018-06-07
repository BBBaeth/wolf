/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:50:05 by ceugene           #+#    #+#             */
/*   Updated: 2018/05/26 14:40:18 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	next_level(t_mlx *list)
{
	close(FD);
	PLAYER->a = 0;
	STAGE->map_nb++;
	read_map(list);
	lets_cast(list);
	image_replacer(list);
}

int		ft_security(t_mlx *list, float x, float y, int key)
{
	if (!(MAP[(int)PLAYER->y][(int)PLAYER->x])
		|| MAP[(int)PLAYER->y][(int)PLAYER->x] == '1'
				|| (key == 126 && MAP[(int)(PLAYER->y + sin(PLAYER->a) * 0.2)]
					[(int)(PLAYER->x + cos(PLAYER->a) * 0.2)] == '1')
					|| (key == 125 &&
						MAP[(int)(PLAYER->y - sin(PLAYER->a) * 0.2)]
							[(int)(PLAYER->x - cos(PLAYER->a) * 0.2)] == '1'))
	{
		PLAYER->x = x;
		PLAYER->y = y;
		return (0);
	}
	if (key == 126 && 
		(MAP[(int)(PLAYER->y + sin(PLAYER->a) * 0.3)][(int)(PLAYER->x)]
			== '1'
				|| MAP[(int)PLAYER->y][(int)(PLAYER->x + cos(PLAYER->a) * 0.3)]
					== '1'))
	{
		PLAYER->x = x;
		PLAYER->y = y;
		return (0);
	}
	return (1);
}

void	place_player(t_mlx *list)
{
	int		select;
	int		s2;

	select = 0;
	PLAYER->x = 0;
	PLAYER->y = 0;
	while (MAP[select][0])
	{
		s2 = 0;
		while (MAP[select][s2])
		{
			if (MAP[select][s2] == 'P')
			{
				if (PLAYER->x == 0 && PLAYER->y == 0)
				{
					PLAYER->x = s2;
					PLAYER->y = select;
				}
				else
					ft_fail("Error: Several spawns detected.", list);
			}
			s2++;
		}
		select++;
	}
}

void	free_them_all(t_mlx *list)
{
	if (list)
	{
		close(FD);
		if (WIN_PTR)
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			mlx_destroy_window(MLX_PTR, WIN_PTR);
		}
	}
}

void	image_replacer(t_mlx *list)
{
	lets_cast(list);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}
