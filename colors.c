/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:45:28 by ceugene           #+#    #+#             */
/*   Updated: 2018/05/18 14:36:37 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	attribute_text_color_to_image(t_mlx *list, int i, int pos, t_point o)
{
	if (list->t[i].data[(int)o.x * list->t[i].bpp
		+ (int)o.y * list->t[i].s_l] + 3 < 255)
	{
		IMG_DATA[pos + 0] = (char)list->t[i].data[(int)o.x * list->t[i].bpp
			+ (int)o.y * list->t[i].s_l];
		IMG_DATA[pos + 1] = (char)list->t[i].data[(int)o.x * list->t[i].bpp
			+ (int)o.y * list->t[i].s_l + 1];
		IMG_DATA[pos + 2] = (char)list->t[i].data[(int)o.x * list->t[i].bpp
			+ (int)o.y * list->t[i].s_l + 2];
		IMG_DATA[pos + 3] = (char)(0 + ((int)DIST * 2 % 200) % 255);
	}
}
