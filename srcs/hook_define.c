/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2022/12/05 23:32:01 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


//int ft_rotate(int keycode, t_fdf *fdf)
//{
//	if (keycode == 0)
//	{
//		fdf->rot->rot_x += 0.05;
//		ft_rotate_x(fdf, fdf->rot.rot_x);
//	}	if (keycode == 2)
//	{
//		fdf->rot->rot_x -= 0.05;
//		ft_rotate_x(fdf, fdf->rot.rot_x);
//	}
//}

int ft_zoom(int keycode, int x, int y, t_fdf *fdf)
{

	(void)y;
	(void)x;

	if (keycode == 4)
	{
		fdf->cam->scale *= 0.95;
		create_img(fdf);
	}
	else if (keycode == 5)
	{
		fdf->cam->scale *= 1.05;
	//	fdf->cam.mouse_x = x;
	//	fdf->cam.mouse_y = y;
		create_img(fdf);
	}
	return (0);
}

int	ft_translate(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT_ARROW) // gauche
	{
		fdf->cam->offset_x -= 10;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		create_img(fdf);
	}
	if (keycode == UP_ARROW) // haut
	{
		fdf->cam->offset_y -= 10;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		create_img(fdf);
	}
	if (keycode == RIGHT_ARROW) // droite
	{
		fdf->cam->offset_x += 10;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		create_img(fdf);
	}
	if (keycode == DOWN_ARROW) // bas
	{
		fdf->cam->offset_y += 10;
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		create_img(fdf);
	}
	return (0);
}

int	ft_hook_keycode(int keycode, t_fdf *fdf)
{
	ft_printf("%d\n", keycode);
	if (keycode == ESC)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	//if (keycode == 69)
// ++
	//if (keycode == 78)
	//	--
	if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW || keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_translate(keycode, fdf);
	//if (keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1 || keycode == 12 | keycode == 14)
	//	ft_rotate(keycode, fdf);
	return (0);
}
void	ft_hook_define(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L<<0, ft_hook_keycode, fdf);
	/*				MOUSE				*/
	mlx_mouse_hook(fdf->mlx_win, ft_zoom, fdf);
}