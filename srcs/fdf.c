/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2023/01/29 01:06:30 by aurel            ###   ########.fr       */
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
	fdf->col.str1 = NULL;
	fdf->col.str2 = NULL;
}

static void	init_struct_main(t_fdf *fdf)
{
	fdf->map = malloc(sizeof(t_map));
	if (!(fdf->map))
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->map' in 'init_struct_main'", 0);
	fdf->data = malloc(sizeof(t_data));
	if (!(fdf->data))
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->data' in 'init_struct_main'", 0);
	fdf->cam = malloc(sizeof(t_tools));
	if (!(fdf->cam))
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->cam' in 'init_struct_main'", 0);
}

void	init_mlx(t_fdf **fdf)
{
	(*fdf)->mlx = mlx_init();
	if (!((*fdf)->mlx))
		exit_fdf(*fdf, MLX_ERR, "in 'init_mlx", 0);
	(*fdf)->mlx_win = mlx_new_window((*fdf)->mlx, (*fdf)->map->width_win, \
		(*fdf)->map->height_win, "FdF");
}

void	clean_fdf(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->mlx2 = NULL;
	fdf->mlx_win = NULL;
	fdf->mlx_win2 = NULL;
	fdf->map = NULL;
	fdf->data = NULL;
	fdf->cam = NULL;
}

void	clean_fdf_sub(t_fdf *fdf)
{
	fdf->cam->h_on = 0;
	fdf->map->tab = NULL;
	fdf->data->img = NULL;
	fdf->data->img = NULL;
	fdf->data->img2 = NULL;
	fdf->data->addr = NULL;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		exit_fdf(NULL, ARGC_ERR, "", 1);
	fdf = NULL;
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		exit_fdf(fdf, MALLOC_ERR, "for 't_fdf' in 'main'", 1);
	clean_fdf(fdf);
	init_struct_main(fdf);
	clean_fdf_sub(fdf);
	parsing(argv[1], fdf);
	init_default_value(fdf);
	fill_palett(fdf);
	fill_palett_next(fdf);
	init_mlx(&fdf);
	ft_hook_define(fdf);
	create_img(fdf);
	print_menu(fdf, H);
	fdf->cam->h_on = 1;
	mlx_loop(fdf->mlx);
}
