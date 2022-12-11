/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2022/12/11 16:13:53 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_chose_color(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_P0)
		fdf->col.palr[0] *= 1.002;
	else if (keycode == NUM_P1)
		fdf->col.palr[1] *= 1.002;
	else if (keycode == NUM_P2)
		fdf->col.palr[2] *= 1.0002;
	else if (keycode == NUM_P3)
		fdf->col.palr[3] *= 1.0002;
	else if (keycode == NUM_P4)
		fdf->col.palr[4] *= 1.0002;
	else if (keycode == NUM_P5)
		fdf->col.palr[5] *= 1.0002;
	else if (keycode == NUM_P6)
		fdf->col.palr[6] *= 1.0002;
	else if (keycode == NUM_P7)
		fdf->col.palr[7] *= 1.0002;
	else if (keycode == NUM_P8)
		fdf->col.palr[8] *= 1.0002;
	else if (keycode == NUM_P9)
		fdf->col.palr[9] *= 1.0002;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
}

void	fill_palett(t_fdf *fdf)
{
	fdf->col.palr[0] = P2_1;
	fdf->col.palr[1] = P2_2;
	fdf->col.palr[2] = P2_3;
	fdf->col.palr[3] = P2_4;
	fdf->col.palr[4] = P2_5;
	fdf->col.palr[5] = P2_6;
	fdf->col.palr[6] = P2_7;
	fdf->col.palr[7] = P2_8;
	fdf->col.palr[8] = P2_9;
	fdf->col.palr[9] = P2_10;

	fdf->col.pal3[0] = P2_1;
	fdf->col.pal3[1] = P2_2;
	fdf->col.pal3[2] = P2_3;
	fdf->col.pal3[3] = P2_4;
	fdf->col.pal3[4] = P2_5;
	fdf->col.pal3[5] = P2_6;
	fdf->col.pal3[6] = P2_7;
	fdf->col.pal3[7] = P2_8;
	fdf->col.pal3[8] = P2_9;
	fdf->col.pal3[9] = P2_10;
}
void fill_palett_next(t_fdf *fdf)
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
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
}

void ft_change_color(int keycode, t_fdf *fdf)
{
	int i;

	i = -1;
	if (keycode == R)
	{
		while (++i < 10)
			fdf->col.palr[i] = fdf->col.pal[i];
	}
	if (keycode == B)
	{
		while (++i < 10)
			fdf->col.palr[i] = fdf->col.pal2[i];
	}
	if (keycode == G)
	{
		while (++i < 10)
			fdf->col.palr[i] = fdf->col.pal3[i];
	}
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
}

void ft_rotate(int keycode, t_fdf *fdf)
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

int ft_zoom(int keycode, int x, int y, t_fdf *fdf)
{

	(void)y;
	(void)x;

	if (keycode == 5)
		fdf->cam->scale *= 0.95;
	else if (keycode == 4)
		fdf->cam->scale *= 1.05;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	return (0);
}

int	ft_translate(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT_ARROW) // gauche
		fdf->cam->offset_x -= 10;
	else if (keycode == UP_ARROW) // haut
		fdf->cam->offset_y -= 10;
	else if (keycode == RIGHT_ARROW) // droite
		fdf->cam->offset_x += 10;
	else if (keycode == DOWN_ARROW) // bas
		fdf->cam->offset_y += 10;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	return (0);
}

int	ft_hook_keycode(int keycode, t_fdf *fdf)
{
	ft_printf("%d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		ft_freetabi(fdf->map->tab);
		ft_free_fdf(fdf, 0);
	}
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW || keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_translate(keycode, fdf);
	else if (keycode == A || keycode == W || keycode == D || keycode == S || keycode == Q || keycode == E)
		ft_rotate(keycode, fdf);
	else if (keycode == R || keycode == G || keycode == B)
		ft_change_color(keycode, fdf);
	else if (keycode == NUM_P0 || keycode == NUM_P1 || keycode == NUM_P2 || keycode == NUM_P3 || keycode == NUM_P4 \
		|| keycode == NUM_P5 || keycode == NUM_P6 || keycode == NUM_P7 || keycode == NUM_P8 \
			|| keycode == NUM_P9)
			ft_chose_color(keycode, fdf);
	else if (keycode == PLUS || keycode == MINUS)
		ft_inc_z(keycode, fdf);
	return (0);
}
void	ft_hook_define(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 1L<<0, ft_hook_keycode, fdf);
	mlx_mouse_hook(fdf->mlx_win, ft_zoom, fdf);
}