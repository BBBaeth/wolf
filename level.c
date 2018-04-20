/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:50:29 by ceugene           #+#    #+#             */
/*   Updated: 2018/04/20 16:07:18 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_player_coordinates(t_mlx *list)
{
	int		select;
	int		select2;
	int		ok;

	ok = 0;
	select2 = 0;
	while (MAP[select2][0])
	{
		select = 0;
		while (MAP[select2][select])
		{
			if (MAP[select2][select] == 'P')
			{
				if (ok != 0)
					ft_fail("Error: Map has several player positions.", list);
				PLAYER->x = select;
				PLAYER->y = select2;
				ok = 1;
			}
			select++;
		}
		select2++;
	}
	if (ok == 0)
		ft_fail("Error: Map needs to give player position (P).", list);
}
