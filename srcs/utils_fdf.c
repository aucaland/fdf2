/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:24:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/06 14:33:24 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_gradient_colors(t_fdf *fdf)
{
	float tmp;

	tmp = fdf->map->min_coeff;
	fdf->col.z_col = fdf->point.z;
	if (fdf->map->min_coeff < 0)
	{
		fdf->map->min_coeff = fdf->map->min_coeff + fdf->map->min_coeff;
		fdf->map->max_coeff = fdf->map->max_coeff + tmp;
		fdf->col.z_col = fdf->point.z + tmp;
	}
	fdf->col->range = 255 / (fdf->map->max_coeff - fdf->map->min_coeff);
	if (fdf->col)


}