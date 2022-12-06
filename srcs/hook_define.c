/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2022/12/06 21:23:19 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_inc_z(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS)
	{
		 fdf->cam->inc_z *= 1.05;
		create_img(fdf);
	}
	if (keycode == MINUS)
	{
		 fdf->cam->inc_z *= 0.95;
		create_img(fdf);
	}
}

void ft_change_color(int keycode, t_fdf *fdf)
{
	if (keycode == R)
	{
		fdf->col.r += 5;
		fdf->col.range = fdf->col.r / (fdf->map->max_coeff - fdf->map->min_coeff);
		create_img(fdf);
	}
	if (keycode == B)
	{
		fdf->col.b += 5;
		fdf->col.range = fdf->col.b / (fdf->map->max_coeff - fdf->map->min_coeff);
		create_img(fdf);
	}
	if (keycode == G)
	{
		fdf->col.g += 5;
		fdf->col.range = fdf->col.g / (fdf->map->max_coeff - fdf->map->min_coeff);
		create_img(fdf);
	}
	if (keycode == T)
	{
		fdf->col.r -= 5;
		fdf->col.range = fdf->col.r / (fdf->map->max_coeff - fdf->map->min_coeff);
		create_img(fdf);
	}
	if (keycode == N)
	{
		fdf->col.b -= 5;
		fdf->col.range = fdf->col.b / (fdf->map->max_coeff - fdf->map->min_coeff);
		create_img(fdf);
	}
	if (keycode == H)
	{
		fdf->col.g -= 5;
		fdf->col.range = fdf->col.g / (fdf->map->max_coeff - fdf->map->min_coeff);
		create_img(fdf);
	}
}

void ft_rotate(int keycode, t_fdf *fdf)//TODO: refactor -25 line
{
	if (keycode == W)
	{
		fdf->cam->rot_x -= 0.02;
		create_img(fdf);
	}
	if (keycode == S)
	{
		fdf->cam->rot_x += 0.02;
		create_img(fdf);
	}
	if (keycode == A)
	{
		fdf->cam->rot_y += 0.02;
		create_img(fdf);
	}
	if (keycode == D)
	{
		fdf->cam->rot_y -= 0.02;
		create_img(fdf);
	}
	if (keycode == Q)
	{
		fdf->cam->rot_z -= 0.02;
		create_img(fdf);
	}
	if (keycode == E)
	{
		fdf->cam->rot_z += 0.02;
		create_img(fdf);
	}

}

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
	if (keycode == A || keycode == W || keycode == D || keycode == S || keycode == Q || keycode == E)
		ft_rotate(keycode, fdf);
	if (keycode == R || keycode == G || keycode == B || keycode == T || keycode == H || keycode == N)
		ft_change_color(keycode, fdf);
	if (keycode == PLUS || keycode == MINUS)
		ft_inc_z(keycode, fdf);
	return (0);
}
void	ft_hook_define(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L<<0, ft_hook_keycode, fdf);
	/*				MOUSE				*/
	mlx_mouse_hook(fdf->mlx_win, ft_zoom, fdf);
}