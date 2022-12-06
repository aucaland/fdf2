/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:24:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/06 18:35:38 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void colors_range(t_fdf *fdf)
{
	int tmp;

	tmp = fdf->map->min_coeff;
	fdf->col.r = 255;
	fdf->col.g = 255;
	fdf->col.b = 255;
	if (fdf->map->min_coeff < 0)
	{
		fdf->map->min_coeff = fdf->map->min_coeff + abs(fdf->map->min_coeff);
		fdf->map->max_coeff = fdf->map->max_coeff + abs(tmp);
		fdf->point.z_for_grad = abs(tmp);
		fdf->col.isneg = 1;
	}
	else if (fdf->map->min_coeff > 0)
	{
		fdf->map->min_coeff = fdf->map->min_coeff - fdf->map->min_coeff;
		fdf->map->max_coeff = fdf->map->max_coeff - tmp;
		fdf->point.z_for_grad = abs(tmp);
		fdf->col.isneg = 0;
	}
	else
		fdf->col.isneg = - 1;
	//ft_printf("ok%d:\n %d:\n", fdf->point.z_for_grad, fdf->map->max_coeff - fdf->map->min_coeff);
	fdf->col.range = 255 / (fdf->map->max_coeff - fdf->map->min_coeff);
	//dprintf(1, "ok%f",fdf->col.range );
	//dprintf(1,"%u", fdf->col.mod);
}


int	ft_gradient_colors(t_fdf *fdf)
{
	fdf->point.new_z = fdf->point.z;
	if (fdf->col.isneg == 1)
		fdf->point.new_z += fdf->point.z_for_grad;

	else if (fdf->col.isneg == 0)
		fdf->point.new_z -= fdf->point.z_for_grad;
//	dprintf(1, "\ncc%d\n", fdf->point.new_z);
	//dprintf(1, "%f", ((fdf->col.range * fdf->point.new_z) / 255) * BLUE_F);
	//ft_printf("%d", (fdf->col.range * (1 / fdf->point.new_z) * 255) * BLUE_F + (fdf->col.range * (1 / fdf->point.new_z) * 255) * RED_F + (fdf->col.range * (1 / fdf->point.new_z) * 255) * GREEN_F);
	return (((fdf->col.range * fdf->point.new_z) / fdf->col.b) * 255 + ((fdf->col.range * fdf->point.new_z) / fdf->col.r) * 255 + ((fdf->col.range * fdf->point.new_z) / fdf->col.g) * 255 + 0.69 * WHITE);
}