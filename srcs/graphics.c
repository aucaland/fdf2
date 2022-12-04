/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:35:19 by aurel             #+#    #+#             */
/*   Updated: 2022/12/04 22:44:40 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


void isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.83);
	*y = (*x + *y) * sin(0.83) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void bresenham(float x0, float y0, float x1, float y1, t_fdf *fdf)
{
	float dx;
	float dy;
	int max;
	int z0;
	int z1;

	z0 = fdf->map->tab[(int)y0][(int)x0] * (fdf->map->max_coeff / (fdf->map->height));
	z1 = fdf->map->tab[(int)y1][(int)x1] * (fdf->map->max_coeff / (fdf->map->height));
	/* zoom */
	x0 *= fdf->windef->scale;
	x1 *= fdf->windef->scale;
	y0 *= fdf->windef->scale;
	y1 *= fdf->windef->scale;

	isometric(&x0, &y0, z0);
	isometric(&x1, &y1, z1);
	x0 += fdf->windef->width_win / 2.6;
	x1 += fdf->windef->width_win / 2.6;
	y0 += fdf->windef->height_win / 3.3;
	y1 += fdf->windef->height_win / 3.3;
	fdf->data->color = BLUE + (GREEN + RED) * (z0 * 100);
	dx = x1 - x0;
	dy = y1 - y0;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int) (x0 - x1) || (int) (y1 - y0))
	{
		if (x0 >= fdf->windef->width_win || x0 <= 0 || y0 <= 0 \
			|| y0 >= fdf->windef->height_win)
			break;
		my_mlx_pixel_put(fdf->data, x0, y0, fdf->data->color);
		x0 += dx;
		y0 += dy;
	}
}

void comput_line(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->map->height)
	{

		x = 0;
		while (x < fdf->map->width)
		{
			if (x > 0)
				bresenham(x, y, x - 1, y, fdf);
			if (y > 0)
				bresenham(x, y, x, y - 1, fdf);
			x++;
		}
		y++;
	}


}
