/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:03:16 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/23 18:01:13 by aurel            ###   ########.fr       */
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

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void check_map(t_fdf *fdf, int nbr_word, int count)
{
	if (nbr_word <= 0)
	{
		ft_putstr_fd("Error parsing : X coordinates are not homogeneous", 2);
		ft_free_fdf(fdf, -1);
	}
	if (count == 1)
	{
		fdf->map->width = nbr_word;
		printf("AFFIL %d\n", fdf->map->height);
	}
	printf("OLD = %d-----NEW = %d\n", fdf->map->width, nbr_word);
	if (nbr_word != fdf->map->width)
	{
		ft_putstr_fd("Error parsing : X coordinates are not homogeneous", 2);
		ft_free_fdf(fdf, -1);
	}
}