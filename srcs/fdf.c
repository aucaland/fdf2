/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2023/02/04 00:12:42 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_default_value(t_fdf *fdf)
{
	fdf->map->width_win = 1900;
	fdf->map->height_win = 1100;
	fdf->cam->proj = 1;
	fdf->cam->h_on = 0;
	if (fdf->map->width > 220)
	{
		fdf->cam->offset_x = fdf->map->width_win / 2.9;
		fdf->cam->offset_y = fdf->map->height_win / 3;
	}
	if (fdf->map->max_coeff >= -1 && fdf->map->max_coeff <= 1)
		fdf->map->max_coeff += 1;
	if (fdf->map->width > 25)
		fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 2;
	else if (fdf->map->width > 12)
		fdf->cam->inc_z = (fdf->map->height_win / fdf->map->max_coeff) / 10;
	fdf->cam->scale = (fdf->map->height_win / \
		(fmax(fdf->map->width, fdf->map->height)));
	fdf->col.str1 = NULL;
	fdf->col.str2 = NULL;
	fdf->col.r = NULL;
	fdf->col.g = NULL;
	fdf->col.b = NULL;
	fdf->col.str1 = NULL;
	fdf->col.str2 = NULL;
}

static void	init_struct_main(t_fdf *fdf)
{
	fdf->map = ft_calloc(sizeof(t_map), 1);
	protect_alloc(fdf, fdf->map, NULL, \
									"for 'fdf->map' in 'init_struct_main'");
	fdf->data = ft_calloc(sizeof(t_data), 1);
	protect_alloc(fdf, fdf->data, NULL, \
									"for 'fdf->data' in 'init_struct_main'");
	fdf->cam = ft_calloc(sizeof(t_tools), 1);
	protect_alloc(fdf, fdf->cam, NULL, \
									"for 'fdf->cam' in 'init_struct_main'");
	fdf->cam->translate_x = 0;
	fdf->cam->translate_y = 0;
}

void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit_fdf(fdf, MLX_INIT_ERR, "in 'init_mlx", 0);
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->map->width_win, \
		fdf->map->height_win, "FdF");
	if (!fdf->mlx_win)
		exit_fdf(fdf, MLX_WIN_ERR, "in 'ml_new_window'", 0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		exit_fdf(NULL, ARGC_ERR, "", 1);
	ft_bzero(&fdf, sizeof (t_fdf));
	init_struct_main(&fdf);
	parsing(argv[1], &fdf);
	init_default_value(&fdf);
	fill_palett(&fdf);
	fill_palett_next(&fdf);
	init_mlx(&fdf);
	ft_hook_define(&fdf);
	create_img(&fdf);
	print_menu(&fdf, H);
	fdf.cam->h_on = 1;
	mlx_loop(fdf.mlx);
}
