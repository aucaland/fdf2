/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:24:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/12 10:57:49 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void ft_free_fdf(t_fdf *fdf, int i)
{
	ft_free(fdf->data);
	ft_free(fdf->cam);
	ft_free(fdf->map);
	ft_free(fdf);
	if (i == 0)
		exit(EXIT_SUCCESS);
	if (i == -1)
		exit(EXIT_FAILURE);
}

int	get_default_color(int z, t_fdf *fdf)
{
	double	percentage;

	percentage = percent((float)fdf->map->min_coeff, (float)fdf->map->max_coeff, z);
	if (percentage < 0.1)
		return (fdf->col.palr[0]);
	else if (percentage < 0.2)
		return (fdf->col.palr[1]);
	else if (percentage < 0.3)
		return (fdf->col.palr[2]);
	else if (percentage < 0.4)
		return (fdf->col.palr[3]);
	else if (percentage < 0.5)
		return (fdf->col.palr[4]);
	else if (percentage < 0.6)
		return (fdf->col.palr[5]);
	else if (percentage < 0.7)
		return (fdf->col.palr[6]);
	else if (percentage < 0.8)
		return (fdf->col.palr[7]);
	else if (percentage < 0.9)
		return (fdf->col.palr[8]);
	else
		return (fdf->col.palr[9]);

}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

/*
** Get color. Result depends on point position.
** This function is needed to create linear gradient.
*/

int	get_color(t_point start, t_point end, t_point point)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	//ft_printf("start : %xend : %x", start.color,end.color);
	//printf("s[%f;%f] - e[%f;%f] -c[%f;%f]\n", start.x, start.y, end.x, end.y, point.curx, point.cury);
	if (point.cur_color == end.color)
		return (point.cur_color);
	//printf("cur : %d ----- end : %d\n", point.cur_color , end.color);
	if (point.dx > point.dy)
		percentage = percent(start.x, end.x, point.curx);
	else
		percentage = percent(start.y, end.y, point.cury);
	//if (percentage != 0)
		//dprintf(1, "%f", percentage);
	red = get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF,
					  (end.color >> 8) & 0xFF,
					  percentage);
	blue = get_light(start.color & 0xFF,
					 end.color & 0xFF,
					 percentage);
	return ((red << 16) | (green << 8) | blue);
}
double	percent(int start, int end,  int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

//void colors_range(t_fdf *fdf)
//{
//	int tmp;
//
//	tmp = fdf->map->min_coeff;
//	fdf->col.r = 125;
//	fdf->col.g = 100;
//	fdf->col.b = 50;
//	if (fdf->map->min_coeff < 0)
//	{
//		fdf->map->min_coeff = fdf->map->min_coeff + abs(fdf->map->min_coeff);
//		fdf->map->max_coeff = fdf->map->max_coeff + abs(tmp);
//		fdf->point.z_for_grad = abs(tmp);
//		fdf->col.isneg = 1;
//	}
//	else if (fdf->map->min_coeff > 0)
//	{
//		fdf->map->min_coeff = fdf->map->min_coeff - fdf->map->min_coeff;
//		fdf->map->max_coeff = fdf->map->max_coeff - tmp;
//		fdf->point.z_for_grad = abs(tmp);
//		fdf->col.isneg = 0;
//	}
//	else
//		fdf->col.isneg = - 1;
//	//ft_printf("ok%d:\n %d:\n", fdf->point.z_for_grad, fdf->map->max_coeff - fdf->map->min_coeff);
//	fdf->col.range_r = 255 / (fdf->map->max_coeff - fdf->map->min_coeff);
//	fdf->col.range_g = 255 / (fdf->map->max_coeff - fdf->map->min_coeff);
//	fdf->col.range_b = 255 / (fdf->map->max_coeff - fdf->map->min_coeff);
//	//dprintf(1, "ok%f",fdf->col.range );
//	//dprintf(1,"%u", fdf->col.mod);
//}
//
//
//int	ft_gradient_colors(t_fdf *fdf)
//{
//	fdf->point.new_z = fdf->point.z;
//	if (fdf->col.isneg == 1)
//		fdf->point.new_z += fdf->point.z_for_grad;
//
//	else if (fdf->col.isneg == 0)
//		fdf->point.new_z -= fdf->point.z_for_grad;
//	//dprintf(1, "\ncc%d\n", fdf->point.new_z);
//	//dprintf(1, "%f", ((fdf->col.range_r * fdf->point.new_z) * 255));
//	//dprintf(1, "%f\n", fdf->col.range_r);
//	//dprintf(1, "%f\n", (((fdf->point.new_z + 0.01) * fdf->col.range_r) * 255 + ((fdf->col.range_b * (fdf->point.new_z + 0.01))) * 255 + ((fdf->col.range_g * (fdf->point.new_z + 0.01))) * 255));
//	return (fdf->col.r + fdf->col.b /(fdf->point.new_z + fdf->col.b) + fdf->col.g);
//}