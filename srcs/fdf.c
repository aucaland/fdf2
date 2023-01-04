/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2023/01/04 13:27:23 by aucaland         ###   ########.fr       */
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
}

void	print_menu(t_fdf *fdf)//TODO : integrer
{
	char	*str;
	char	*str1;
	char	*str2;

	str = NULL;
	str1 = NULL;
	str2 = NULL;
	if (fdf->col.palr[0] == P0_1)
		str = "Palette 1 HYPERCHILL";
	if (fdf->col.palr[0] == P1_1)
		str = "Palette 2 NEON_SPACE";
	if (fdf->col.palr[0] == P2_1)
		str = "Palette 3 Perso";
	if (str != NULL)
	{
		fdf->str = ft_strjoin("Colors :", str);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, fdf->str);
		free(fdf->str);
	}
	if (str == NULL)
	{
		int r = fdf->col.palr[0] >> 16;
		int g = fdf->col.palr[0] >> 8 & 255;
		int b = fdf->col.palr[0] & 255;
		fdf->str = ft_strjoin("ALT 0 : R=", ft_itoa(r));
		str1 = ft_strjoin(" G=", ft_itoa(g));
		str2 = ft_strjoin(" B=", ft_itoa(b));
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, "--Manual--\n");
		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 50, GREEN_F * 0.5, fdf->str);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 195, 50, GREEN_F * 0.5, str1);
		mlx_string_put(fdf->mlx, fdf->mlx_win, 260, 50, GREEN_F * 0.5, str2);

//		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, fdf->str);
//		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, fdf->str);
//		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, fdf->str);
//		mlx_string_put(fdf->mlx, fdf->mlx_win, 65, 20, GREEN_F * 0.5, fdf->str);
		free(fdf->str);
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
	print_menu(fdf);
	ft_hook_define(fdf);
	create_img(fdf);
	mlx_loop(fdf->mlx);
}
