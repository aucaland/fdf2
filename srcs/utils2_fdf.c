/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:03:16 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 09:43:29 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	(void)fdf;
	*x = (*x - *y) * cos(0.60);
	*y = (*x + *y) * sin(0.60) - z * (cos(0.5555) - sin(0.5555)) \
		* (fdf->cam->scale / (fdf->map->height_win / fdf->map->height));
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
