/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2022/12/05 10:39:43 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int ft_zoom(int keycode, int x, int y, t_fdf *fdf)
{

	if (keycode == 4)
	{
		fdf->windef->scale *= 0.95;
		fdf->windef->cam.mouse_x = x;
		fdf->windef->cam.mouse_y = y;
		create_img(fdf);
	}
	else if (keycode == 5)
	{
		fdf->windef->scale *= 1.05;
		fdf->windef->cam.mouse_x = x;
		fdf->windef->cam.mouse_y = y;
		create_img(fdf);
	}
	return (0);
}

int	ft_move(int keycode, t_fdf *fdf)
{
	if (keycode == 123) // gauche
	{
		fdf->windef->cam.center_x -= 5;
		create_img(fdf);
	}
	if (keycode == 126) // haut
	{
		fdf->windef->cam.center_y -= 5;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		create_img(fdf);
	}
	if (keycode == 124) // droite
	{
		fdf->windef->cam.center_x += 5;
		create_img(fdf);
	}
	if (keycode == 125) // bas
	{
		fdf->windef->cam.center_y += 5;
		create_img(fdf);
	}
	return (0);
}

int	ft_hook_keycode(int keycode, t_fdf *fdf)
{
	ft_printf("%d\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	//if (keycode == 69)
// ++
	//if (keycode == 78)
	//	--
	if (keycode == 123 || keycode == 124 || keycode == 126 || keycode == 125)
		ft_move(keycode, fdf);
	return (0);
}
void	ft_hook_define(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L<<0, ft_hook_keycode, fdf);
	/*				MOUSE				*/
	mlx_mouse_hook(fdf->mlx_win, ft_zoom, fdf);
}