/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:41:44 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/09 18:59:04 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_hook_define(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L << 0, ft_hook_keycode, fdf);
	mlx_hook(fdf->mlx_win, 2, 1L << 0, button_press, fdf);
	mlx_mouse_hook(fdf->mlx_win, ft_zoom, fdf);
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

int	button_press(int keycode, t_fdf *fdf)
{
	if (keycode == 17)
	{
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		ft_freetabi(fdf->map->tab, fdf->map->nbr_line);
		ft_free_fdf(fdf, 0);
	}
	return (0);
}
