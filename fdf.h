/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:56 by aurel             #+#    #+#             */
/*   Updated: 2022/12/01 21:03:41 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx.h"
# include "libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

typedef struct list_map
{
	void *content;
	struct list_map *next;
}l_map;

int	is_space(const char str);

#endif
