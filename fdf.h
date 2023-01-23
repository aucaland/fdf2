/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:56 by aurel             #+#    #+#             */
/*   Updated: 2023/01/23 09:16:12 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx_linux/mlx.h"
# include "LIBFT/libft.h"
# include <math.h>
# include "define_utils.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

# if defined(__linux__)
#  include "Linux/keycode_linux.h"
# elif	defined(__MACH__)
#  include "Mac/keycode_mac.h"
# endif

typedef struct s_data {
	void			*img;
	void			*img2;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				color;
}						t_data;

typedef struct s_map
{
	int				height;
	int				width;
	int				**tab;
	int				max_coeff;
	int				min_coeff;
	int				height_win;
	int				width_win;
	int				nbr_line;

}						t_map;

typedef struct s_tools
{
	float			offset_x;
	float			offset_y;
	float			scale;
	double			rot_x;
	double			rot_y;
	double			rot_z;
	float			inc_z;
	int				h_on;
	int				proj;
}						t_tools;

typedef struct s_point
{
	float			x;
	float			y;
	int				z;
	float			dx;
	float			dy;
	float			curx;
	float			cury;
	unsigned int	color;
	unsigned int	cur_color;
}						t_point;

typedef struct s_point2
{
	float			x;
	float			y;
	int				z;
	unsigned int	color;
}		t_point2;

typedef struct s_fdf
{
	void			*mlx;
	void			*mlx2;
	void			*mlx_win;
	void			*mlx_win2;
	char			*str;
	t_map			*map;
	t_data			*data;
	t_tools			*cam;
	t_point			point;
	t_point2		points;
	t_col			col;
}						t_fdf;

/*					Rotate					*/

int					is_space(const char str);

			/*				HOOKs			*/

int					ft_hook_keycode(int keycode, t_fdf *fdf);
int					ft_hook_keycode2(int keycode, t_fdf *fdf);
void				ft_hook_define(t_fdf *fdf);
int					ft_translate(int keycode, t_fdf *fdf);
int					ft_zoom(int keycode, int x, int y, t_fdf *fdf);
void				ft_rotate(int keycode, t_fdf *fdf);
void				ft_rotate_x(float *y, int *z, double rot_x);
void				ft_rotate_y(float *x, int *z, double rot_y);
void				ft_rotate_z(float *x, float *y, double rot_z);
void				ft_inc_z(int keycode, t_fdf *fdf);
void				ft_inc_z2(t_fdf *fdf);
void				ft_change_color(int keycode, t_fdf *fdf);
void				ft_chose_color(int keycode, t_fdf *fdf);
int					button_press(t_fdf *fdf);
int					ft_hook_key_release(int keycode, t_fdf *fdf);

			/*					PARSING				*/

void				parsing(char *path, t_fdf *fdf);
int					ft_read_map(char *file);
void				init_default_value(t_fdf *fdf);
void				check_map(t_fdf *fdf, int nbr_word, int count);
void				set_map_z(t_fdf *fdf, int nbr_word, \
						char *list_content, int i);

			/*				Graph				*/

void				comput_line(t_fdf *fdf);
void				ft_print_map(t_fdf *fdf);
void				create_img(t_fdf *fdf);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point				proj(t_fdf *fdf);
t_fdf				*new_point(int x, int y, t_fdf *fdf);
void				isometric(float *x, float *y, int z, t_fdf *fdf);
void				bresenham(t_point coord0, t_point coord1, t_fdf *fdf);

			/*						Colors					*/

int					ft_gradient_colors(t_fdf *fdf);
void				colors_range(t_fdf *fdf);
double				percent(int start, int end, int current);
int					find_gradient_value(int start, int end, double percentage);
int					get_color(t_point start, t_point end, t_point point);
int					get_default_color(int z, t_fdf *fdf);
void				fill_palett(t_fdf *fdf);
void				fill_palett_next(t_fdf *fdf);

			/*						MENU					*/

void				print_menu(t_fdf *fdf, int Keycode);
void				print_menu2(t_fdf *fdf, int Keycode);
void				free_menu(t_fdf *fdf, char *str, char *str1, char *str2);
void				print_menu3(t_fdf *fdf, int Keycode);
void				colors_menu(t_fdf *fdf, int i);
void				colors_menu2(t_fdf *fdf, int i);
			/*						free					*/

void				ft_free_fdf(t_fdf *fdf, int i);
#endif
