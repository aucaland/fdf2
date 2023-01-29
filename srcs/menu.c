/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:17 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/29 18:51:24 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_menu(t_fdf *fdf, int Keycode)
{
	if (Keycode == H)
	{
		if (fdf->cam->h_on == 1)
			mlx_destroy_image(fdf->mlx, fdf->data->img2);
		fdf->data->img2 = mlx_new_image(fdf->mlx, 400, 900);
		if (!fdf->data->img2)
			exit_fdf(fdf, MLX_IMG_ERR, "for 'fdf->img2' in 'print_menu'",0);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img2, 0, 0);
	}
	print_menu_curr_colors(fdf, Keycode);
}

void	print_menu_curr_colors(t_fdf *fdf, int Keycode)
{
	int		i;

	i = 0;
	while (i <= 9)
	{
		colors_menu(fdf, i);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 122, 20, \
		GREEN_F * 0.48, "--CURRENT COLORS--\n");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 70, 50 + i * 3, \
		WHITE * 0.55, fdf->str);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 235, 50 + i * 3, \
		WHITE * 0.55, fdf->col.str1);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 295, 50 + i * 3, \
		WHITE * 0.55, fdf->col.str2);
		free_menu(fdf);
		i += 9;
	}
	print_menu_guide(fdf, Keycode);
}

void	print_menu_guide(t_fdf *fdf, int Keycode)
{
	if (Keycode == H)
	{
		mlx_string_put(fdf->mlx, fdf->mlx_win, 150, 160, \
		GREEN_F * 0.48, "--HELP (H)--");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 200, \
		WHITE * 0.55, "ALT_MIN_Z : NUM1/2/3 = R/G/B");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 230, \
		WHITE * 0.55, "ALT_MAX_Z : NUM7/8/9 = R/G/B");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 260, \
		WHITE * 0.55, "Reset_Colors_ALL : NUMPAD 0");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 290, \
		WHITE * 0.55, "Reset_Colors_ALT_MIN : NUMPAD 4");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 320, \
		WHITE * 0.55, "Reset_Colors_ALT_MAX : NUMPAD 5");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 350, \
		WHITE * 0.55, "Zoom : +/-");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 380, \
		WHITE * 0.55, "Rotate Z : E/Q");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 410, \
		WHITE * 0.55, "Translate : Arrows");
	}
}

void	colors_menu(t_fdf *fdf, int i)
{
	fdf->col.r = ft_itoa(fdf->col.palr[i] >> 16 & 255);
	protect_alloc(fdf, fdf->col.r, NULL, "for 'fdf->col.r' in 'colors_menu'");
	fdf->col.g = ft_itoa(fdf->col.palr[i] >> 8 & 255);
	if (fdf->col.g == NULL)
		protect_alloc(fdf, fdf->col.g, fdf->col.r, "for 'col.g' in col_menu");
	fdf->col.b = ft_itoa(fdf->col.palr[i] & 255);
	if (fdf->col.b == NULL)
	{
		free_menu(fdf);
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->col.b' in 'colors_menu'", 0);
	}
	if (i == 0)
	{
		fdf->str = ft_strjoin("ALT_MIN_Z : R=", fdf->col.r);
		if (!fdf->str)
		{
			free_menu(fdf);
			exit_fdf(fdf, MALLOC_ERR, "for 'fdf->str' in 'colors_menu'", 0);
		}
	}
	colors_menu2(fdf, i);
}

void	colors_menu2(t_fdf *fdf, int i)
{
	if (i != 0)
	{
		fdf->str = ft_strjoin("ALT_MAX_Z : R=", fdf->col.r);
		if (!fdf->str)
		{
			free_menu(fdf);
			exit_fdf(fdf, MALLOC_ERR, "for 'fdf->str' in 'colors_menu2'", 0);
		}
	}
	fdf->col.str1 = ft_strjoin(" G=", fdf->col.g);
	if (!fdf->col.str1)
	{
		free_menu(fdf);
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->col->str1' in 'colors_menu2", 0);
	}
	fdf->col.str2 = ft_strjoin(" B=", fdf->col.b);
	if (!fdf->col.str2)
	{
		free_menu(fdf);
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->col->str2' in 'colors_menu2", 0);
	}
}
