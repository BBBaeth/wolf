/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:24:11 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/20 16:52:20 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		window_closed(t_mlx *list)
{
	free_them_all(list);
	exit(0);
}

int		key_pressed(int key, t_mlx *list)
{
	if (key == 126 || key == 125)
		move_dir(key, list);
	else if (key == 123 || key == 124)
		move_side(key, list);
	return (0);
}

int		move_dir(int key, t_mlx *list)
{
	float	x;
	float	y;

	x = PLAYER->x;
	y = PLAYER->y;
	if (key == 126)
	{
		PLAYER->x += cos(PLAYER->a) * 0.2;
		PLAYER->y += sin(PLAYER->a) * 0.2;
	}
	else if (key == 125)
	{
		PLAYER->x -= cos(PLAYER->a) * 0.2;
		PLAYER->y -= sin(PLAYER->a) * 0.2;
	}
	if (ft_security(list, x, y, key))
		image_replacer(list);
	return (0);
}

int		move_side(int key, t_mlx *list)
{
	if (key == 123)
		PLAYER->a -= 0.15 * 0.19;
	else if (key == 124)
		PLAYER->a += 0.15 * 0.19;
	if (PLAYER->a >= 6.30 || PLAYER->a <= -6.30)
		PLAYER->a = 0;
	image_replacer(list);
	return (0);
}

int		key_manager(int key, void *list)
{
	if (key == 53 || key == 12)
		window_closed(list);
	if (key == 35)
		next_level(list);
	return (0);
}
