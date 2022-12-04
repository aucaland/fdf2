/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:56 by aurel             #+#    #+#             */
/*   Updated: 2022/12/04 15:35:12 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx/mlx_linux/mlx.h"
# include "LIBFT/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

typedef struct s_map
{
	int height;
	int width;
	int	**tab;

}				t_map;

typedef struct s_mlx
{
	int height_win;
	int width_win;
	int scale;
} 				t_win;

typedef struct s_fdf
{
	void *mlx;
	void *mlx_win;
	t_map *map;
	t_data *data;
	t_win *windef;

}				t_fdf;

int	is_space(const char str);

/*				HOOKs			*/

int	close_win(int keycode, t_fdf *fdf);

/*					PARSING				*/

void	parsing(char *path, t_fdf *fdf);
int	ft_read_map(char *file);

/*				Graph				*/

void comput_line(t_fdf *fdf);

#endif
