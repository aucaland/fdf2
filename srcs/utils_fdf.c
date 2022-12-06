/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:24:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/06 16:20:16 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void colors_range(t_fdf *fdf)
{
	float tmp;

	tmp = fdf->map.min_coeff;
	if (fdf->map.min_coeff < 0)
	{
		fdf->map->min_coeff = fdf->map.min_coeff + fdf->map.min_coeff;
		fdf->map->max_coeff = fdf->map.max_coeff + tmp;
		fdf->point.z_for_grad = tmp;
		fdf->col.mod = neg;
	}
	if (fdf->map->min_coeff > 0)
	{
		fdf->map->min_coeff = fdf->map.min_coeff - fdf->map.min_coeff;
		fdf->map->max_coeff = fdf->map.max_coeff - tmp;
		fdf->point.z_for_grad = tmp;
		fdf->col.mod = pos;
	}
	fdf->col->range = 255 / (fdf->map->max_coeff - fdf->map->min_coeff);
}

int	ft_gradient_colors(t_fdf *fdf)
{
	fdf->point->new_z = fdf->point.z;
	if (fdf->col.mod == neg)
		fdf->point.new_z += fdf->point.z_for_grad;
	else if (fdf->col.mod == pos)
		fdf->point.new_z -= fdf->point.z_for_grad;
	return ((fdf->col->range * (1 / fdf->point.new_z) * 255) * BLUE_F + (fdf->col->range * (1 / fdf->point.new_z) * 255) * RED_F + (fdf->col->range * (1 / fdf->point.new_z) * 255) * GREEN_F);


}