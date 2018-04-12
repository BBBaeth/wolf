#include "wolf.h"

t_texture	*xpm_texture(char *name, t_mlx *list)
{
	t_texture		*text;

	if (!(text = malloc(sizeof(t_texture) * 1)))
		ft_fail("Error: Unable to allocate memory.", list);
	if (!(text->ptr = mlx_xpm_file_to_image(MLX_PTR, name, &text->width,
		&text->height)))
		ft_fail("Error: Cannot read texture files.", list);
	if (!(text->data = mlx_get_data_addr(text->ptr, &text->bpp, &text->s_l,
		&text->endian)))
		ft_fail("Error: Cannot read texture files.", list);
	text->bpp = text->bpp / 8;
	text->width = text->s_l / text->bpp;
	text->height = text->width;
	return (text);
}

void	free_textures(t_mlx *list)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (list->t[i] != NULL)
		{
			if (list->t[i]->ptr)
				mlx_destroy_image(MLX_PTR, list->t[i]->ptr);
			free(list->t[i]);
			list->t[i] = NULL;
		}
		i++;
	}
}

void	generate_texture(t_mlx *list)
{
	if (!(*(list->t) = malloc(sizeof(t_texture*) * 6)))
		ft_fail("Error: Unable to allocate memory.", list);
	list->t[0] = xpm_texture("./tex/wall1.xpm", list);
	list->t[1] = xpm_texture("./tex/wall2.xpm", list);
	list->t[2] = xpm_texture("./tex/wall3.xpm", list);
	list->t[3] = xpm_texture("./tex/wall4.xpm", list);
}