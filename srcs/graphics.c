/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:35:19 by aurel             #+#    #+#             */
/*   Updated: 2022/12/04 15:43:45 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>
#define ABS(_x) ((_x) >= 0 ? (_x) : -(_x))
#define SGN(_x) ((_x) < 0 ? -1 : \
						 ((_x) > 0 ? 1 : 0))

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void horizontal_octant(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	// more horizontal than vertical
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incX = SGN(dx);
	int incY = SGN(dy);
	dx = ABS(dx);
	dy = ABS(dy);
	int slope = 2 * dy;
	int error = -dx;
	int errorInc = -2 * dx;
	int y = y0;

	for (int x = x0; x != x1 + incX; x += incX)
	{
		my_mlx_pixel_put(fdf->data, x, y, 0x00FF0000);
		error += slope;

		if (error >= 0)
		{
			y += incY;
			error += errorInc;
		}
	}
}

void vertical_octant(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	// more vertical than horizontal
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incX = SGN(dx);
	int incY = SGN(dy);
	dx = ABS(dx);
	dy = ABS(dy);
	int slope = 2 * dx;
	int error = -dy;
	int errorInc = -2 * dy;
	int x = x0;

	for (int y = y0; y != y1 + incY; y += incY)
	{
		my_mlx_pixel_put(fdf->data, x, y, 0x00FF0000);
		error += slope;

		if (error >= 0)
		{
			x += incX;
			error += errorInc;
		}
	}
}

void bresenham(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incX = SGN(dx);
	int incY = SGN(dy);
	dx = ABS(dx);
	dy = ABS(dy);

	if (dy == 0)
	{
		for (int x = x0; x != x1 + incX; x += incX)
			my_mlx_pixel_put(fdf->data, x, y0, 0x00FF0000);
	}
	else if (dx == 0)
	{

		for (int y = y0; y != y1 + incY; y += incY)
			my_mlx_pixel_put(fdf->data, x0, y, 0x00FF0000);

	}
	else if (dx >= dy)
		horizontal_octant(x0, y0, x1, y1, fdf);
	else
		vertical_octant(x0, y0, x1, y1, fdf);
}

void comput_line(t_fdf *fdf)
{
	int x;
	int y;
	int scale;

	scale = fdf->windef->scale;
	y = 0;
	while (y < fdf->map->height)
	{

		x = 0;
		while (x < fdf->map->width)
		{
			bresenham(x * scale, y * scale, x * scale + 1 * scale, y * scale, fdf);
			bresenham(x * scale, y * scale, x * scale, y * scale + 1 * scale, fdf);
			x++;
		}
		y++;
	}


}
