/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2022/12/05 10:18:19 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_fdf *init_struct_main()//TODO: init all struct
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (free(fdf), fdf = NULL, NULL);
	fdf->map = malloc(sizeof(t_map));
	if (!(fdf->map))
		return (ft_free(fdf->map, sizeof(t_map)), NULL);
	fdf->data = malloc(sizeof(t_data));
	if (!(fdf->data))
		return (ft_free(fdf->map, sizeof(t_map)), ft_free(fdf, sizeof(t_fdf)), NULL);
	fdf->windef = malloc(sizeof(t_win));
	if (!(fdf->windef))
	{
		ft_free(fdf->map, sizeof(t_map));
		return (ft_free(fdf->data, sizeof(t_data)), ft_free(fdf, sizeof(t_fdf)), NULL);
	}
	return (fdf);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_fdf	*fdf;

	fdf = init_struct_main();
	parsing(argv[1], fdf);
	fdf->windef->width_win = 1980;
	fdf->windef->height_win = 1080;
	fdf->windef->cam.mouse_x = 0;
	fdf->windef->cam.mouse_y = 0;
	fdf->windef->cam.center_x = 0;
	fdf->windef->cam.center_y = 0;
	fdf->windef->scale = (fdf->windef->height_win) / (fdf->map->height + (fdf->map->height * 0.6));
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->windef->width_win, fdf->windef->height_win, "Hello ok");
	ft_hook_define(fdf);
	create_img(fdf);
	mlx_loop(fdf->mlx);
}