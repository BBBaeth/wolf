#include "wolf.h"

int		window_closed(t_mlx *list)
{
	if (list)
	{
		free_textures(list);
		close(FD);
		if (MAP)
			free(MAP);
		if (STAGE)
			free(STAGE);
		if (PLAYER)
			free(PLAYER);
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
	if (!(MAP[(int)PLAYER->y][(int)PLAYER->x])
		|| MAP[(int)PLAYER->y][(int)PLAYER->x] == '1' || (key == 126 && MAP[(int)(PLAYER->y + sin(PLAYER->a))][(int)(PLAYER->x + cos(PLAYER->a))] == '1') || (key == 125 && MAP[(int)(PLAYER->y - sin(PLAYER->a))][(int)(PLAYER->x - cos(PLAYER->a))] == '1'))
	{
		PLAYER->x = x;
		PLAYER->y = y;
	}
	image_replacer(list);
	return (0);
}

int		move_side(int key, t_mlx *list)
{
	if (key == 123)
		PLAYER->a -= 0.15 * 0.09;
	else if (key == 124)
		PLAYER->a += 0.15 * 0.09;
	if (PLAYER->a >= 6.30 || PLAYER->a <= -6.30)
		PLAYER->a = 0;
	image_replacer(list);
	return (0);
}

int		key_manager(int key, void *list)
{
	if (key == 53 || key == 12)
		window_closed(list);
	if (key == 123 || key == 124)
		move_side(key, list);
	if (key == 126 || key == 125)
		move_dir(key, list);
	if (key == 35)
		next_level(list);
	return (0);
}
