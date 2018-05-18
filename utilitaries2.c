#include "wolf.h"

void	reload_pic(t_mlx *list)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

void	next_level(t_mlx *list)
{
	close(FD);
	STAGE->map_nb++;
	read_map(list);
	lets_cast(list);
	image_replacer(list);
}

int		ft_security(t_mlx *list, float x, float y, int key)
{
	if (!(MAP[(int)PLAYER->y][(int)PLAYER->x])
		|| MAP[(int)PLAYER->y][(int)PLAYER->x] == '1'
				|| (key == 126 && MAP[(int)(PLAYER->y + sin(PLAYER->a))]
					[(int)(PLAYER->x + cos(PLAYER->a))] == '1')
					|| (key == 125 && MAP[(int)(PLAYER->y - sin(PLAYER->a))]
						[(int)(PLAYER->x - cos(PLAYER->a))] == '1'))
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
		if (MAP)
			free(MAP);
		MAP = NULL;
		if (STAGE)
			free(STAGE);
		STAGE = NULL;
		if (PLAYER)
			free(PLAYER);
		PLAYER = NULL;
		if (WIN_PTR)
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			mlx_destroy_window(MLX_PTR, WIN_PTR);
			if (IMG_DATA)
				free(IMG_DATA);
		}
		free(list);
		list = NULL;
	}
}

void	image_replacer(t_mlx *list)
{
	lets_cast(list);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}
