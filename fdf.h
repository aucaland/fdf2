/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:56 by aurel             #+#    #+#             */
/*   Updated: 2022/12/06 16:26:44 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx/mlx_linux/mlx.h"
# include "LIBFT/libft.h"
# include <math.h>
# include "define_utils.h"
#if defined(__linux__)
# include "Linux/keycode_linux.h"
#elif	defined(__MACH__)
#include "Mac/keycode_mac.h"
#endif
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	color;
}				t_data;



typedef struct s_map
{
	int height;
	int width;
	int	**tab;
	int max_coeff;
	int min_coeff;
	int height_win;
	int width_win;

}				t_map;

typedef struct s_tools
{
	int	mouse_x;
	int  mouse_y;
	float offset_x;
	float offset_y;
	float scale_change;
	float scale;
	double rot_x;
	double rot_y;
	double rot_z;

}				t_tools;

typedef struct s_point
{
	float x;
	float y;
	int z;
	int new_z;
	int z_for_grad;
}				t_point;

typedef struct s_fdf
{
	void *mlx;
	void *mlx_win;
	t_map *map;
	t_data *data;
	t_tools	*cam;
	t_point point;
	t_col 	col;

}				t_fdf;

/*					Rotate					*/

int	is_space(const char str);

/*				HOOKs			*/

int	ft_hook_keycode(int keycode, t_fdf *fdf);
void	ft_hook_define(t_fdf *fdf);
int ft_translate(int keycode, t_fdf *fdf);
int ft_zoom(int keycode, int x, int y, t_fdf *fdf);
void ft_rotate(int keycode, t_fdf *fdf);
void ft_rotate_x(float *y, int *z, double rot_x);
void ft_rotate_y(float *x, int *z, double rot_y);
void ft_rotate_z(float *x, float *y, double rot_z);

/*					PARSING				*/

void	parsing(char *path, t_fdf *fdf);
int	ft_read_map(char *file);

/*				Graph				*/

void comput_line(t_fdf *fdf);
void ft_print_map(t_fdf *fdf);
void create_img(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point	proj(t_fdf *fdf);
t_fdf *new_point(int x, int y, t_fdf *fdf);
void isometric(float *x, float *y, int z, t_fdf *fdf);
void bresenham(t_point coord0, t_point coord1, t_fdf *fdf);




#endif
