/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:41:44 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/20 16:15:23 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	proj_plane(t_fdf *fdf)
{
	if (fdf->cam->proj == 0)
	{
		reset_map(fdf);
		if (fdf->map->width > 25)
			fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 2;
		else if (fdf->map->width > 12)
			fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 10;
		fdf->cam->scale = (fdf->map->height_win / \
		(fmax(fdf->map->width, fdf->map->height)));
		fdf->cam->proj = 1;
	}
	else
	{
		reset_map(fdf);
		if (fdf->map->width > 25)
			fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 2;
		else if (fdf->map->width > 12)
			fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 10;
		fdf->cam->scale = (fdf->map->height_win / \
		(fmax(fdf->map->width, fdf->map->height)));
		fdf->cam->proj = 0;
	}
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
}

void	ft_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == W)
		fdf->cam->rot_x -= 0.02;
	else if (keycode == S)
		fdf->cam->rot_x += 0.02;
	else if (keycode == A)
		fdf->cam->rot_y += 0.02;
	else if (keycode == D)
		fdf->cam->rot_y -= 0.02;
	else if (keycode == Q)
		fdf->cam->rot_z -= 0.02;
	else if (keycode == E)
		fdf->cam->rot_z += 0.02;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	if (fdf->cam->h_on == 1)
		print_menu(fdf, H);
}

void	ft_inc_z(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS)
	{
		if (fdf->cam->inc_z > 50)
			return ;
		if (fdf->cam->inc_z <= 0.1 || fdf->cam->inc_z >= -0.1)
			fdf->cam->inc_z += 0.2;
		if (fdf->cam->inc_z < 0)
			fdf->cam->inc_z *= 0.98;
		else
			fdf->cam->inc_z *= 1.02;
	}
	if (keycode == MINUS)
	{
		if (fdf->cam->inc_z < -50)
			return ;
		if (fdf->cam->inc_z <= 0.1 || fdf->cam->inc_z >= -0.1)
			fdf->cam->inc_z -= 0.2;
		if (fdf->cam->inc_z < 0)
			fdf->cam->inc_z *= 1.02;
		else
			fdf->cam->inc_z *= 0.98;
	}
	ft_inc_z2(fdf);
}

void	ft_inc_z2(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	if (fdf->cam->h_on == 1)
		print_menu(fdf, H);
}

int	button_press(t_fdf *fdf)
{
	ft_free_fdf(fdf, 0);
	return (0);
}
