/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2023/01/30 10:20:44 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_hook_define(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L << 0, ft_hook_keycode, fdf);
	mlx_hook(fdf->mlx_win, 17, 1L << 0, button_press, fdf);
	mlx_mouse_hook(fdf->mlx_win, ft_zoom, fdf);
}

int	ft_zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)y;
	(void)x;
	if (keycode == 5)
	{
		fdf->cam->inc_z *= 0.96;
		fdf->cam->scale *= 0.96;
	}
	else if (keycode == 4)
	{
		fdf->cam->inc_z *= 1.04;
		fdf->cam->scale *= 1.04;
	}
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	if (fdf->cam->h_on == 1)
		print_menu(fdf, H);
	return (0);
}

int	ft_translate(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT_ARROW)
		fdf->cam->offset_x -= 6;
	else if (keycode == UP_ARROW)
		fdf->cam->offset_y -= 6;
	else if (keycode == RIGHT_ARROW)
		fdf->cam->offset_x += 6;
	else if (keycode == DOWN_ARROW)
		fdf->cam->offset_y += 6;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	if (fdf->cam->h_on == 1)
		print_menu(fdf, H);
	return (0);
}

int	ft_hook_keycode(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit_fdf(fdf, "", "", 0);
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
	else
		ft_hook_keycode2(keycode, fdf);
	return (0);
}

int	ft_hook_keycode2(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS || keycode == MINUS)
		ft_inc_z(keycode, fdf);
	else if (keycode == H && fdf->cam->h_on == 0)
	{
		print_menu(fdf, H);
		fdf->cam->h_on = 1;
	}
	else if (keycode == H && fdf->cam->h_on == 1)
	{
		fdf->cam->h_on = 0;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		mlx_destroy_image(fdf->mlx, fdf->data->img2);
		create_img(fdf);
	}
	else if (keycode == P)
	{
		if (fdf->cam->proj == 0)
			fdf->cam->proj = 1;
		else
			fdf->cam->proj = 0;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		create_img(fdf);
	}
	return (0);
}
