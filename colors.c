#include "wolf.h"

void	attribute_text_color_to_image(t_mlx *list, int i, int pos, t_point o)
{
	IMG_DATA[pos + 0] = (char)list->t[i]->data[(int)o.x * list->t[i]->bpp
		+ (int)o.y * list->t[i]->s_l];
	IMG_DATA[pos + 1] = (char)list->t[i]->data[(int)o.x * list->t[i]->bpp
		+ (int)o.y * list->t[i]->s_l + 1];
	IMG_DATA[pos + 2] = (char)list->t[i]->data[(int)o.x * list->t[i]->bpp
		+ (int)o.y * list->t[i]->s_l + 2];
}
