/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:38:51 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/20 16:23:46 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	convert_rgb(t_fdf *fdf, int nbr_rgb, int nbr_tab)
{
	if (nbr_rgb == 0)
		return (fdf->col.pal2[nbr_tab] + 5);
	else if (nbr_rgb == 1)
		return (fdf->col.pal2[nbr_tab] + (5 << 8));
	else
		return (fdf->col.pal2[nbr_tab] + (5 << 16));
}

void	ft_chose_color(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_P3)
		fdf->col.pal2[0] = convert_rgb(fdf, 0, 0);
	else if (keycode == NUM_P2)
		fdf->col.pal2[0] = convert_rgb(fdf, 1, 0);
	else if (keycode == NUM_P1)
		fdf->col.pal2[0] = convert_rgb(fdf, 2, 0);
	else if (keycode == NUM_P9)
		fdf->col.pal2[9] = convert_rgb(fdf, 0, 9);
	else if (keycode == NUM_P8)
		fdf->col.pal2[9] = convert_rgb(fdf, 1, 9);
	else if (keycode == NUM_P7)
		fdf->col.pal2[9] = convert_rgb(fdf, 2, 9);
	if (keycode == NUM_P0)
	{
		fdf->col.pal2[0] = 0x303030;
		fdf->col.pal2[9] = 0x303030;
	}
	else if (keycode == NUM_P4)
		fdf->col.pal2[0] = 0x303030;
	else if (keycode == NUM_P5)
		fdf->col.pal2[9] = 0x303030;
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	if (fdf->cam->h_on == 1)
		print_menu(fdf, H);
}

void	fill_palett(t_fdf *fdf)
{
	fdf->col.palr[0] = P1_1;
	fdf->col.palr[1] = P1_2;
	fdf->col.palr[2] = P1_3;
	fdf->col.palr[3] = P1_4;
	fdf->col.palr[4] = P1_5;
	fdf->col.palr[5] = P1_6;
	fdf->col.palr[6] = P1_7;
	fdf->col.palr[7] = P1_8;
	fdf->col.palr[8] = P1_9;
	fdf->col.palr[9] = P1_10;
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

void	fill_palett_next(t_fdf *fdf)
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

void	ft_change_color(int keycode, t_fdf *fdf)
{
	int	i;

	i = -1;
	if (keycode == R)
	{
		while (++i < 10)
			fdf->col.pal2[i] = fdf->col.pal[i];
	}
	if (keycode == B)
	{
		while (++i < 10)
			fdf->col.pal2[i] = fdf->col.palr[i];
	}
	if (keycode == G)
	{
		while (++i < 10)
			fdf->col.pal2[i] = fdf->col.pal3[i];
	}
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	create_img(fdf);
	if (fdf->cam->h_on == 1)
		print_menu(fdf, H);
}
