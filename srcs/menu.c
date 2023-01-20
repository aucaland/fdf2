/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:17 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/20 16:37:31 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_menu(t_fdf *fdf, int Keycode)
{
	char	*str;

	str = NULL;
	if (Keycode == H)
	{
		if (fdf->cam->h_on == 1)
			mlx_destroy_image(fdf->mlx, fdf->data->img2);
		fdf->data->img2 = mlx_new_image(fdf->mlx, 400, 900);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img2, 0, 0);
	}
	if (fdf->col.palr[0] == P0_1 && fdf->col.palr[9] == P0_1)
		str = "Palette 1 HYPERCHILL";
	if (fdf->col.palr[0] == P1_1 && fdf->col.palr[9] == P1_1)
		str = "Palette 2 NEON_SPACE";
	if (fdf->col.palr[0] == P2_1 && fdf->col.palr[9] == P2_1)
		str = "Palette 3 Perso";
	if (str != NULL)
	{
		fdf->str = ft_strjoin("Colors :", str);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, fdf->str);
		free(fdf->str);
	}
	else
		print_menu2(fdf, Keycode);
}

void	print_menu2(t_fdf *fdf, int Keycode)
{
	int		i;

	i = 0;
	while (i <= 9)
	{
		colors_menu(fdf, i);
		colors_menu2(fdf, i);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, \
		GREEN_F * 0.5, "--Manual Colors--\n");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 50 + i * 3, \
		GREEN_F * 0.9, fdf->str);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 215, 50 + i * 3, \
		GREEN_F * 0.9, fdf->col.str1);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 275, 50 + i * 3, \
		GREEN_F * 0.9, fdf->col.str2);
		free_menu(fdf, fdf->str, fdf->col.str1, fdf->col.str2);
		i += 9;
	}
	print_menu3(fdf, Keycode);
}

void	print_menu3(t_fdf *fdf, int Keycode)
{
	if (Keycode == H)
	{
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 200, \
		GREEN_F * 0.9, "ALT 0 : NUM1/2/3 = R/G/B");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 230, \
		GREEN_F * 0.9, "ALT 1 : NUM7/8/9 = R/G/B");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 260, \
		GREEN_F * 0.9, "Reset Color : 0");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 290, \
		GREEN_F * 0.9, "Reset ALT 0 : 0");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 320, \
		GREEN_F * 0.9, "Reset ALT 1 : 0");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 350, \
		GREEN_F * 0.9, "Zoom : +/-");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 380, \
		GREEN_F * 0.9, "Rotate Z : E/Q");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 410, \
		GREEN_F * 0.9, "Translate : Arrows");
	}
}

void	colors_menu(t_fdf *fdf, int i)
{
	fdf->col.r = ft_itoa(fdf->col.palr[i] >> 16 & 255);
	if (fdf->col.r == NULL)
		ft_free_fdf(fdf, -1);
	fdf->col.g = ft_itoa(fdf->col.palr[i] >> 8 & 255);
	if (fdf->col.g == NULL)
	{
		free(fdf->col.r);
		ft_free_fdf(fdf, -1);
	}
	fdf->col.b = ft_itoa(fdf->col.palr[i] & 255);
	if (fdf->col.b == NULL)
	{
		free(fdf->col.r);
		free(fdf->col.g);
		ft_free_fdf(fdf, -1);
	}
}

void	colors_menu2(t_fdf *fdf, int i)
{
	if (i == 0)
		fdf->str = ft_strjoin("ALT MIN : R=", fdf->col.r);
	else
		fdf->str = ft_strjoin("ALT MAX : R=", fdf->col.r);
	if (!fdf->str)
		ft_free_fdf(fdf, -1);
	fdf->col.str1 = ft_strjoin(" G=", fdf->col.g);
	if (!fdf->col.str1)
	{
		free(fdf->str);
		ft_free_fdf(fdf, -1);
	}
	fdf->col.str2 = ft_strjoin(" B=", fdf->col.b);
	if (!fdf->col.str2)
	{
		free(fdf->col.str1);
		free(fdf->str);
		ft_free_fdf(fdf, -1);
	}
}
