/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:03:16 by aucaland          #+#    #+#             */
/*   Updated: 2023/02/03 23:21:38 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	float	tmp_x;

	(void)fdf;
	tmp_x = *x;
	*x = (*x - *y) * cos(0.45);
	*y = (tmp_x + *y) * sin(0.45) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel));
	*(unsigned int *)dst = color;
}

void	check_map(t_fdf *fdf, int nbr_word, int count)
{
	if (nbr_word <= 0)
	{
		fdf->map->map_valid = 0;
		return ;
	}
	if (count == 1)
		fdf->map->width = nbr_word;
	if (nbr_word != fdf->map->width)
	{
		fdf->map->map_valid = 0;
		return ;
	}
	fdf->map->map_valid = 1;
}
