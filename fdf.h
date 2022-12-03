/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:56 by aurel             #+#    #+#             */
/*   Updated: 2022/12/03 11:56:40 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx/mlx_macos/mlx.h"
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
	int	**tab;

}	t_map;

typedef struct s_fdf
{
	t_map *map;
	t_data *data;
} t_fdf;
int	is_space(const char str);


#endif
