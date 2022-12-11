/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:35:19 by aurel             #+#    #+#             */
/*   Updated: 2022/12/11 18:55:28 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	proj(t_fdf *fdf)
{
	fdf->point.x *= fdf->cam->scale;
	fdf->point.y *= fdf->cam->scale;
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

void	bresenham(t_point coord0, t_point coord1, t_fdf *fdf)
{
	int	max;

	fdf->point.dx = coord1.x - coord0.x;
	fdf->point.dy = coord1.y - coord0.y;
	max = fmax(fabs(fdf->point.dx), fabs(fdf->point.dy));
	fdf->point.dx /= max;
	fdf->point.dy /= max;

	while ((int)(coord1.x - coord0.x) || (int)(coord1.y - coord0.y))
	{
		fdf->point.curx = coord0.x;
		fdf->point.cury = coord0.y;
		fdf->point.cur_color = coord0.color;
		if (!(coord0.x >= fdf->map->width_win || coord0.x <= 0 || coord0.y <= 0 \
			|| coord0.y >= fdf->map->height_win))
			my_mlx_pixel_put(fdf->data, coord0.x, coord0.y, \
				get_color(fdf->point, coord1, fdf->point));
		coord0.x += fdf->point.dx;
		coord0.y += fdf->point.dy;
	}
}

t_fdf	*new_point(int x, int y, t_fdf *fdf)
{
	fdf->point.x = x;
	fdf->point.y = y;
	fdf->point.z = fdf->map->tab[y][x];
	fdf->point.color = get_default_color(fdf->point.z, fdf);
	fdf->point.z *= fdf->cam->inc_z;
	return (fdf);
}

void	comput_line(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;

	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(proj(new_point(x, y, fdf)), \
					proj(new_point(x + 1, y, fdf)), fdf);
			if (y < fdf->map->height - 1)
				bresenham(proj(new_point(x, y, fdf)), \
					proj(new_point(x, y + 1, fdf)), fdf);
			x++;
		}
		ft_printf("%d", fdf->map->width);
		y++;
	}
}

void	create_img(t_fdf *fdf)
{
	fdf->data->img = mlx_new_image(fdf->mlx, \
	fdf->map->width_win, fdf->map->height_win);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, \
	&fdf->data->bits_per_pixel, \
			&fdf->data->line_length, &fdf->data->endian);
	comput_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img, 0, 0);
}
