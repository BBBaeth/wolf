#include "wolf.h"

void	reload_pic(t_mlx *list)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

void	next_level(t_mlx *list)
{
	STAGE->map_nb++;
	read_map(list);
	lets_cast(list);
	image_replacer(list);
}

void	image_replacer(t_mlx *list)
{
	void	*stmp;

	mlx_destroy_image(MLX_PTR, IMG_PTR);
	if (!(stmp = mlx_new_image(MLX_PTR, LA, HA)))
		ft_fail("Error: Unable to generate image.", list);
	IMG_PTR = stmp;
	lets_cast(list);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}
