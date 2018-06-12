
#include "wolf.h"

void		place_the_player2(t_mlx *list)
{
	PLAYER->x += 0.5;
	PLAYER->y += 0.5;
	if (PLAYER->y < 1 || PLAYER->x <= 1 || PLAYER->y >= STAGE->map_ha
		|| PLAYER->x >= STAGE->map_la
			|| MAP[(int)PLAYER->y][(int)PLAYER->x] == '1')
		ft_fail("Error: Player spawn is invalid.", list);
}

void		choice_selected(t_mlx *list)
{
	if (MENU_S == 0)
	{
		IN_MENU = 0;
		image_replacer(list);
	}
	if (MENU_S == 1)
	{
	}
	else if (MENU_S == 2)
		window_closed(list);
}

void		lets_write(t_mlx *list)
{
	mlx_string_put(MLX_PTR, WIN_PTR, 190, 300, 0xFFFFFFF, "PLAY\n");
	mlx_string_put(MLX_PTR, WIN_PTR, 190, 390, 0xFFFFFFF, "MAP\n");
	mlx_string_put(MLX_PTR, WIN_PTR, 190, 480, 0xFFFFFFF, "QUIT\n");
}

void		lets_highlight(t_mlx *list)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	while (i < 250)
	{
		j = 0;
		while (j < 80)
		{
			pos = (((150 + i) * BPP) + ((280 + (90 * MENU_S) + j) * S_L));
			IMG_DATA[pos + 0] += (char)30;
			IMG_DATA[pos + 1] += (char)30;
			IMG_DATA[pos + 2] += (char)30;
			IMG_DATA[pos + 3] = (char)0;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

void		lets_draw_menu(t_mlx *list)
{
	int		i;
	int		j;
	int		pos;

	bzero(IMG_DATA, S_L * HA);
	i = 0;
	while (i < LA)
	{
		j = 0;
		while (j < HA)
		{
			pos = (i* BPP + j * S_L);
			IMG_DATA[pos + 0] = (char)80;
			IMG_DATA[pos + 1] = (char)30;
			IMG_DATA[pos + 2] = (char)30;
			IMG_DATA[pos + 3] = (char)0;
			j++;
		}
		i++;
	}
	lets_highlight(list);
	lets_write(list);
}

