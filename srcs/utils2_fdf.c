/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:03:16 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/10 14:14:20 by aucaland         ###   ########.fr       */
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

void	check_map(t_fdf *fdf, int nbr_word, int count)
{
	if (nbr_word <= 0)
	{
		ft_putendl_fd("Error parsing : X coordinates are not homogeneous", 2);
		ft_free_fdf(fdf, -1);
	}
	if (count == 1)
		fdf->map->width = nbr_word;
	if (nbr_word != fdf->map->width)
	{
		ft_putendl_fd("Error parsing : X coordinates are not homogeneous", 2);
		ft_free_fdf(fdf, -1);
	}
}

void	free_menu(t_fdf *fdf, char *str, char *str1, char *str2)
{
	free(str);
	str = NULL;
	free(str2);
	str2 = NULL;
	free(str1);
	str1 = NULL;
	free(fdf->col.r);
	fdf->col.r = NULL;
	free(fdf->col.g);
	fdf->col.g = NULL;
	free(fdf->col.b);
	fdf->col.b = NULL;
}
