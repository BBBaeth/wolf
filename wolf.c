/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:50:11 by ceugene           #+#    #+#             */
/*   Updated: 2018/05/26 14:50:05 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_list(t_mlx *list)
{
	HA = 840;
	LA = 1300;
	if (!(MLX_PTR = mlx_init()))
		ft_fail("Error: Connection failed.", list);
	if (!(WIN_PTR = mlx_new_window(MLX_PTR, LA, HA, "WOLF3D")))
		ft_fail("Error: Unable to create window.", list);
	if (!(IMG_PTR = mlx_new_image(MLX_PTR, LA, HA)))
		ft_fail("Error: Unable to create image.", list);
	if (!(IMG_DATA = mlx_get_data_addr(IMG_PTR, &BPP, &S_L, &END)))
		ft_fail("Error: Unable to access image data.", list);
	BPP = BPP / 8;
	STAGE = new_stage(list);
	STAGE->map_nb = 0;
	MAXDIST = 35;
	STEP = 0.01;
	PLAYER = new_player(list);
	FOV = 0.5231;
	SPEED = 0.2;
	generate_texture(list);
}

void	reload_pic(t_mlx *list)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

int		main(int argc, char **argv)
{
	t_mlx	*list;

	if (argc && argv)
	{
		list = new_list();
		init_list(list);
		read_map(list);
		lets_cast(list);
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
		let_mlx_loop(list);
	}
	return (0);
}
