/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:26:30 by ceugene           #+#    #+#             */
/*   Updated: 2018/05/26 14:37:12 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define MLX_PTR list->mlx_ptr
# define WIN_PTR list->win_ptr
# define IMG_PTR list->img_ptr
# define IMG_DATA list->img_data
# define LA list->l
# define HA list->h
# define BPP list->bit_pix
# define S_L list->size_line
# define END list->endian
# define KD list->keys
# define O_A list->a_orgn
# define O_B list->b_orgn
# define HW list->help_w
# define HW_PTR list->hw_ptr
# define STAGE list->map_nb
# define MAP list->map
# define FD list->file_d
# define PLAYER list->player
# define FOV list->fieldofvision
# define WALL1_PTR list->tex_wall1
# define WALL2_PTR list->tex_wall2
# define WALL1_DATA list->wall1_data
# define WALL2_DATA list->wall2_data
# define T_BPP list->tex_bit_pix
# define T_S_L list->tex_size_line
# define T_END list->tex_endian
# define ROOF list->roof
# define FLOOR list->floor
# define UP list->looking_up
# define RIGHT list->right
# define WALLH list->wall_height
# define WALLR list->height_ratio
# define DIST list->distance
# define WINDOW_SIZE list->window_size
# define MAXDIST list->maximal_distance
# define STEP list->step_size
# define RAY list->rayon
# define SPEED list->speed
# define SQ_NB list->square_nb
# define SQ_S list->square_size
# define IN_MENU list->inside_menu
# define MENU_S list->menu_selection
# define MENU_MNB list->menu_map_nb

typedef struct			s_point
{
	float		x;
	float		y;
}						t_point;

typedef struct			s_texture
{
	void				*ptr;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					s_l;
	int					endian;
}						t_texture;

typedef struct			s_player
{
	float				x;
	float				y;
	float				a;
	float				eye_x;
	float				eye_y;
}						t_player;

typedef struct			s_level
{
	int					map_nb;
	char				*map_name;
	int					map_la;
	int					map_ha;
}						t_level;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	long				l;
	long				h;
	int					bit_pix;
	int					size_line;
	int					endian;
	int					keys;
	float				distance;
	float				a_orgn;
	float				b_orgn;
	float				zoom;
	int					help_w;
	void				*hw_ptr;
	t_level				*map_nb;
	char				**map;
	int					file_d;
	t_player			*player;
	float				fieldofvision;
	void				*tex_wall1;
	void				*tex_wall2;
	char				*wall1_data;
	char				*wall2_data;
	int					tex_bit_pix;
	int					tex_size_line;
	int					tex_endian;
	int					roof;
	int					floor;
	int					looking_up;
	int					right;
	t_texture			*t;
	int					wall_height;
	float				height_ratio;
	int					window_size;
	float				maximal_distance;
	float				step_size;
	float				rayon;
	float				speed;
	int					minimap_h;
	int					minimap_l;
	int					**minimap;
	int					square_nb;
	int					square_size;
	int					inside_menu;
	int					menu_selection;
	int					menu_map_nb;
}						t_mlx;

void		ft_fail(char *str, t_mlx *list);
t_mlx		*new_list(void);
t_level		*new_stage(t_mlx *list);
t_player	*new_player(t_mlx *list);
void		read_map(t_mlx *list);
void		lets_cast(t_mlx *list);
int			key_manager(int key, void *list);
int			window_closed(t_mlx *list);
void		let_mlx_loop(t_mlx *list);
void		image_replacer(t_mlx *list);
void		generate_texture(t_mlx *list);
void		next_level(t_mlx *list);
void		attribute_text_color_to_image(t_mlx *list, int i, int p, t_point o);
float		get_ox(t_mlx *list, float dist, int i);
int			key_pressed(int key, t_mlx *list);
int			move_dir(int key, t_mlx *list);
int			move_side(int key, t_mlx *list);
int			ft_security(t_mlx *list, float x, float y, int key);
void		color_sky_and_floor(int x, t_mlx *list);
void		ft_draw_wall(t_mlx *list, int i, int x, t_point o);
void		free_them_all(t_mlx *list);
void		place_player(t_mlx *list);
void		place_the_player2(t_mlx *list);
void		draw_square(t_mlx *list);
void		minimap_table(t_mlx *list);
void		color_squares(t_mlx *list, int startx, int starty, int wall);
void		lets_draw_menu(t_mlx *list);
void		lets_write(t_mlx *list);
void		choice_selected(t_mlx *list);
int			map_searcher(t_mlx *list);
int			name_gen(t_mlx *list);

#endif
