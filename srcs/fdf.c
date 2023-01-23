/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2023/01/23 09:53:21 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_default_value(t_fdf *fdf)
{
	fdf->map->width_win = 1980;
	fdf->map->height_win = 1080;
	fdf->cam->proj = 1;
	fdf->cam->offset_x = fdf->map->width_win / 2.3;
	fdf->cam->offset_y = fdf->map->height_win / 2.3;
	if (fdf->map->max_coeff >= -1 && fdf->map->max_coeff <= 1)
		fdf->map->max_coeff += 1;
	fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 10;
	fdf->cam->scale = (fdf->map->height_win / \
		fmax(fdf->map->width, fdf->map->height));
	fdf->col.str1 = NULL;
	fdf->col.str2 = NULL;
	fdf->col.r = NULL;
	fdf->col.g = NULL;
	fdf->col.b = NULL;
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
	fdf->map->tab = NULL;
	return (fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_putendl_fd("ERROR : Only one argument is valid -->\
			Here an example : './fdf user/map.fdf' ", 2);
		exit(EXIT_FAILURE);
	}
	fdf = init_struct_main();
	if (!fdf)
	{
		ft_putendl_fd("Malloc allocation failed for struct", 2);
		exit(EXIT_FAILURE);
	}
	parsing(argv[1], fdf);
	init_default_value(fdf);
	fill_palett(fdf);
	fill_palett_next(fdf);
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->map->width_win, \
		fdf->map->height_win, "FdF");
	ft_hook_define(fdf);
	create_img(fdf);
	print_menu(fdf, H);
	fdf->cam->h_on = 1;
	mlx_loop(fdf->mlx);
}
