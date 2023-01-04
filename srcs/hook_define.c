/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2023/01/04 11:40:40 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
}

int	ft_zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)y;
	(void)x;
	if (keycode == 5)
		fdf->cam->scale *= 0.96;
	else if (keycode == 4)
		fdf->cam->scale *= 1.04;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	return (0);
}

int	ft_translate(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT_ARROW)
		fdf->cam->offset_x -= 10;
	else if (keycode == UP_ARROW)
		fdf->cam->offset_y -= 10;
	else if (keycode == RIGHT_ARROW)
		fdf->cam->offset_x += 10;
	else if (keycode == DOWN_ARROW)
		fdf->cam->offset_y += 10;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	return (0);
}

int	ft_hook_keycode(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		ft_printf("%d", fdf->map->nbr_line);
		ft_freetabi(fdf->map->tab, fdf->map->nbr_line);
		ft_free_fdf(fdf, 0);
	}
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW || \
		keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_translate(keycode, fdf);
	else if (keycode == A || keycode == W || keycode == D || \
		keycode == S || keycode == Q || keycode == E)
		ft_rotate(keycode, fdf);
	else if (keycode == R || keycode == G || keycode == B)
		ft_change_color(keycode, fdf);
	else if (keycode == NUM_P0 || keycode == NUM_P1 || keycode == NUM_P2 || \
		keycode == NUM_P3 || keycode == NUM_P4 \
		|| keycode == NUM_P5 || keycode == NUM_P6 || \
		keycode == NUM_P7 || keycode == NUM_P8 \
		|| keycode == NUM_P9)
		ft_chose_color(keycode, fdf);
	else if (keycode == PLUS || keycode == MINUS)
		ft_inc_z(keycode, fdf);
	return (0);
}
