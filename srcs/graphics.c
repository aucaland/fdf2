/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:35:19 by aurel             #+#    #+#             */
/*   Updated: 2022/12/07 20:17:56 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


t_point	proj(t_fdf *fdf)
{
	fdf->point.x *= fdf->cam->scale;
	fdf->point.y *= fdf->cam->scale;
	//ft_printf("%d\n", fdf->point.y);
	//fdf->data->color = ft_gradient_colors(fdf);
	fdf->point.z *= ((fdf->map->max_coeff * 0.4) / (fdf->map->height * 0.1));
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
	(void)fdf;
	*x = (*x - *y) * cos(0.60);
	*y = (*x + *y) * sin(0.60) - z * (cos(0.5555) - sin(0.5555)) * (fdf->cam->scale / (fdf->map->height_win / fdf->map->height));
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
	int max;
	//int z0;
	//int z1;
	//z0 = fdf->map->tab[(int)y0][(int)x0] * ((fdf->map->max_coeff) / (fdf->map->height * 0.3));
	//z1 = fdf->map->tab[(int)y1][(int)x1] * ((fdf->map->max_coeff) / (fdf->map->height * 0.3));
	/* zoom */
	fdf->point.dx = coord1.x - coord0.x;
	fdf->point.dy = coord1.y - coord0.y;
	max = fmax(fabs(fdf->point.dx), fabs(fdf->point.dy));
	fdf->point.dx /= max;
	fdf->point.dy /= max;
	fdf->point.curx = coord1.x;
	fdf->point.cury = coord1.y;
	fdf->point.cur_color = coord1.color;
	while ((int) (coord0.x - coord1.x) || (int) (coord1.y - coord0.y))
	{
		if (coord0.x >= fdf->map->width_win || coord0.x <= 0 || coord0.y <= 0 \
			|| coord0.y >= fdf->map->height_win)
			break;
		my_mlx_pixel_put(fdf->data, coord0.x, coord0.y, get_color(coord1, coord0, fdf->point));
		coord0.x += fdf->point.dx;
		coord0.y += fdf->point.dy;
	}
}

t_fdf *new_point(int x, int y, t_fdf *fdf)
{
	fdf->point.x = x;
//	ft_printf("%d", fdf->point.z);
	fdf->point.y = y;
	fdf->point.z = fdf->map->tab[y][x];
//	printf("%d\n", get_default_color(fdf->point.z, fdf));
	fdf->point.color = get_default_color(fdf->point.z, fdf);
	fdf->point.z *= fdf->cam->inc_z;
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
				bresenham(proj(new_point(x, y, fdf)),proj(new_point(x - 1, y, fdf)), fdf);
			if (y > 0)
				bresenham(proj(new_point(x, y, fdf)),proj(new_point(x, y - 1, fdf)), fdf);
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