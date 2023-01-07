/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2023/01/07 01:44:48 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_default_value(t_fdf *fdf)
{
	fdf->map->width_win = 1980;
	fdf->map->height_win = 1080;
	fdf->cam->offset_x = fdf->map->width_win / 3;
	fdf->cam->offset_y = fdf->map->height_win / 3;
	fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 10;
	fdf->cam->scale = (fdf->map->height_win / \
		fmax(fdf->map->width, fdf->map->height));
	fdf->cam->h_on = 0;
}

void	print_menu(t_fdf *fdf, int Keycode)//TODO : integrer
{
	char	*str;
	char	*str1;
	char	*str2;
	int i;

	str = NULL;
	str1 = NULL;
	str2 = NULL;
	i = 0;
	if (Keycode == H)
	{
		fdf->data->img2 = mlx_new_image(fdf->mlx, \
				500, 900);
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
	if (str == NULL)
	{
		while (i <= 9)
		{
			char	*r = ft_itoa(fdf->col.palr[i] >> 16 & 255);
			char	*g = ft_itoa(fdf->col.palr[i] >> 8 & 255);
			char	*b = ft_itoa(fdf->col.palr[i] & 255);

			if (i == 0)
				fdf->str = ft_strjoin("ALT MIN : R=", r);
			else
				fdf->str = ft_strjoin("ALT MAX : R=", r);
			str1 = ft_strjoin(" G=", g);
			str2 = ft_strjoin(" B=", b);
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, "--Manual Colors--\n");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 50 + i * 3, GREEN_F * 0.9, fdf->str);
			mlx_string_put(fdf->mlx, fdf->mlx_win, 215, 50 + i * 3, GREEN_F * 0.9, str1);
			mlx_string_put(fdf->mlx, fdf->mlx_win, 275, 50 + i * 3, GREEN_F * 0.9, str2);
			free(fdf->str);
			free(str1);
			free(str2);
			free(r);
			free(g);
			free(b);
			i += 9;

		}
		if (Keycode == H)
		{
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 200, GREEN_F * 0.9, "ALT 0 : NUM1/2/3 = R/G/B");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 230, GREEN_F * 0.9, "ALT 1 : NUM7/8/9 = R/G/B");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 260, GREEN_F * 0.9, "Reset Color : 0");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 290, GREEN_F * 0.9, "Reset ALT 0 : 0");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 320, GREEN_F * 0.9, "Reset ALT 1 : 0");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 350, GREEN_F * 0.9, "Zoom : +/-");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 380, GREEN_F * 0.9, "Rotate Z : E/Q");
			mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 410, GREEN_F * 0.9, "Translate : Arrows");
		}

	}
}

static t_fdf	*init_struct_main(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (free(fdf), fdf = NULL, NULL);
	fdf->map = malloc(sizeof(t_map));
	if (!(fdf->map))
		return (ft_free(fdf), NULL);
	fdf->data = malloc(sizeof(t_data));
	if (!(fdf->data))
		return (ft_free(fdf->map), ft_free(fdf), NULL);
	fdf->cam = malloc(sizeof(t_tools));
	if (!(fdf->cam))
	{
		ft_free(fdf->data);
		return (ft_free(fdf->map), ft_free(fdf), NULL);
	}
	return (fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		fprintf(stderr, "ERROR : Only one argument is valid -->\
			Here an example : './fdf user/map.fdf' ");
		exit(EXIT_FAILURE);
	}
	fdf = init_struct_main();
	if (!fdf)
	{
		ft_putstr_fd("Malloc allocation failed for struct", 2);
		exit(EXIT_FAILURE);
	}
	parsing(argv[1], fdf);
	init_default_value(fdf);
	fill_palett(fdf);
	fill_palett_next(fdf);
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->map->width_win, \
		fdf->map->height_win, "FdF");
	print_menu(fdf, H);
	ft_hook_define(fdf);
	create_img(fdf);
	mlx_loop(fdf->mlx);
}
