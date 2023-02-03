/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:24:28 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/28 23:11:46 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_default_color(int z, t_fdf *fdf)
{
	double	percentage;

	percentage = percent((float)fdf->map->min_coeff, \
	(float)fdf->map->max_coeff, z);
	if (percentage < 0.1)
		return (fdf->col.pal2[0]);
	else if (percentage < 0.2)
		return (fdf->col.pal2[1]);
	else if (percentage < 0.3)
		return (fdf->col.pal2[2]);
	else if (percentage < 0.4)
		return (fdf->col.pal2[3]);
	else if (percentage < 0.5)
		return (fdf->col.pal2[4]);
	else if (percentage < 0.6)
		return (fdf->col.pal2[5]);
	else if (percentage < 0.7)
		return (fdf->col.pal2[6]);
	else if (percentage < 0.8)
		return (fdf->col.pal2[7]);
	else if (percentage < 0.9)
		return (fdf->col.pal2[8]);
	else
		return (fdf->col.pal2[9]);
}

int	find_gradient_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point start, t_point end, t_point point)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (point.cur_color == end.color)
		return (point.cur_color);
	if (point.dx > point.dy)
		percentage = percent(start.x, end.x, point.curx);
	else
		percentage = percent(start.y, end.y, point.cury);
	red = find_gradient_value((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF,
			percentage);
	green = find_gradient_value((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF,
			percentage);
	blue = find_gradient_value(start.color & 0xFF,
			end.color & 0xFF,
			percentage);
	return ((red << 16) | (green << 8) | blue);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}
