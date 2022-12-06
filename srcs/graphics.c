/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:35:19 by aurel             #+#    #+#             */
/*   Updated: 2022/12/06 14:03:37 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


t_point	proj(t_fdf *fdf)
{
	fdf->point.x *= fdf->cam->scale;
	fdf->point.y *= fdf->cam->scale;
	fdf->point.z *= ((fdf->map->max_coeff * 0.8) / (fdf->map->height * 0.1));
	fdf->data->color =  BLUE_F * 0.4 + RED_F * fdf->point.z * 0.2 + WHITE * 0.4;
	fdf->point.x -= (fdf->map->width * fdf->cam->scale) / 2;
	fdf->point.y -= (fdf->map->height * fdf->cam->scale) / 2;
	ft_rotate_x(&fdf->point.y, &fdf->point.z, fdf->cam->rot_x);
	ft_rotate_y(&fdf->point.x, &fdf->point.z, fdf->cam->rot_y);
	ft_rotate_z(&fdf->point.x, &fdf->point.y, fdf->cam->rot_z);
	isometric(&fdf->point.x, &fdf->point.y, fdf->point.z, fdf);
	fdf->point.x += (fdf->map->width) / 2 + fdf->cam->offset_x;
	fdf->point.y += (fdf->map->height) / 2 + fdf->cam->offset_y;
	return (fdf->point);
}

void isometric(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(0.60);
	*y = (*x + *y) * sin(0.60) - z * (cos(0.5555) - sin(0.5555)) * (fdf->cam->scale  / (fdf->map->height_win / fdf->map->height));
	//*z = cos(0.5555) - sin(0.5555);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void bresenham(t_point coord0, t_point coord1, t_fdf *fdf)
{
	float dx;
	float dy;
	int max;
	//int z0;
	//int z1;


	//z0 = fdf->map->tab[(int)y0][(int)x0] * ((fdf->map->max_coeff) / (fdf->map->height * 0.3));
	//z1 = fdf->map->tab[(int)y1][(int)x1] * ((fdf->map->max_coeff) / (fdf->map->height * 0.3));
	/* zoom */
	dx = coord1.x - coord0.x;
	dy = coord1.y - coord0.y;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int) (coord0.x - coord1.x) || (int) (coord1.y - coord0.y))
	{
		if (coord0.x >= fdf->map->width_win || coord0.x <= 0 || coord0.y <= 0 \
			|| coord0.y >= fdf->map->height_win)
			break;
		my_mlx_pixel_put(fdf->data, coord0.x, coord0.y, fdf->data->color);
		coord0.x += dx;
		coord0.y += dy;
	}
}

t_fdf *new_point(int x, int y, t_fdf *fdf)
{
	fdf->point.x = x;
	fdf->point.y = y;
	fdf->point.z = fdf->map->tab[y][x];
	//TODO: color here
	return (fdf);
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
				bresenham(proj(new_point(x, y, fdf)), proj(new_point(x - 1, y, fdf)), fdf);
			if (y > 0)
				bresenham(proj(new_point(x, y, fdf)), proj(new_point(x, y - 1, fdf)), fdf);
			x++;
		}
		y++;
	}
}

void create_img(t_fdf *fdf)
{
	fdf->data->img = mlx_new_image(fdf->mlx, fdf->map->width_win, fdf->map->height_win);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bits_per_pixel, &fdf->data->line_length,
										&fdf->data->endian);

	comput_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img,0, 0);
}