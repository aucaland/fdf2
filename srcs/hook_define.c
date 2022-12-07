/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2022/12/07 16:40:19 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void fill_palett(t_fdf *fdf)
{
	fdf->col.pal[0] = P0_1;
	fdf->col.pal[1] = P0_2;
	fdf->col.pal[2] = P0_3;
	fdf->col.pal[3] = P0_4;
	fdf->col.pal[4] = P0_5;
	fdf->col.pal[5] = P0_6;
	fdf->col.pal[6] = P0_7;
	fdf->col.pal[7] = P0_8;
	fdf->col.pal[8] = P0_9;
	fdf->col.pal[9] = P0_10;

	fdf->col.pal2[0] = P1_1;
	fdf->col.pal2[1] = P1_2;
	fdf->col.pal2[2] = P1_3;
	fdf->col.pal2[3] = P1_4;
	fdf->col.pal2[4] = P1_5;
	fdf->col.pal2[5] = P1_6;
	fdf->col.pal2[6] = P1_7;
	fdf->col.pal2[7] = P1_8;
	fdf->col.pal2[8] = P1_9;
	fdf->col.pal2[9] = P1_10;

}//TODO : changer tout

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
	int i;

	i = 0;
	if (keycode == R)
	{
		while (i < 10)
		{
			fdf->col.palr[i] = fdf->col.pal[i];
			i++;
		}
		create_img(fdf);
	}
	if (keycode == B)
	{
		while (i < 10)
		{
			fdf->col.palr[i] = fdf->col.pal2[i];
			i++;
		}
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

	if (keycode == 5)
	{
		fdf->cam->scale *= 0.95;
		create_img(fdf);
	}
	else if (keycode == 4)
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
	if (keycode == R || keycode == G || keycode == B)
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