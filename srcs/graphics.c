/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:35:19 by aurel             #+#    #+#             */
/*   Updated: 2022/12/05 15:10:30 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


void isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.72);
	*y = (*x + *y) * sin(0.72) - z;
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

	z0 = fdf->map->tab[(int)y0][(int)x0] * ((fdf->map->max_coeff) / (fdf->map->height * 0.3));
	z1 = fdf->map->tab[(int)y1][(int)x1] * ((fdf->map->max_coeff) / (fdf->map->height * 0.3));
	/* zoom */
	x0 *= fdf->windef->scale;
	x1 *= fdf->windef->scale;
	y0 *= fdf->windef->scale;
	y1 *= fdf->windef->scale;

	isometric(&x0, &y0, z0);
	isometric(&x1, &y1, z1);
	x0 += fdf->windef->cam.offset_x;
	x1 += fdf->windef->cam.offset_x;
	y0 += fdf->windef->cam.offset_y;
	y1 += fdf->windef->cam.offset_y;
	fdf->data->color = BLUE * 0.4 + RED * z0 * 0.2 + WHITE * 0.4;
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

void create_img(t_fdf *fdf)
{
	fdf->data->img = mlx_new_image(fdf->mlx, fdf->windef->width_win, fdf->windef->height_win);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bits_per_pixel, &fdf->data->line_length,
										&fdf->data->endian);

	comput_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img,0, 0);
}