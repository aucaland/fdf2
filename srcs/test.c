/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2022/12/04 15:50:38 by aurel            ###   ########.fr       */
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
	fdf->windef->height_win = 900;
	fdf->windef->width_win = 800;
	fdf->windef->scale = (fdf->windef->height_win) / (fdf->map->height + (fdf->map->height * 0.3));
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->windef->height_win, fdf->windef->width_win, "Hello ok");
	mlx_hook(fdf->mlx_win, 2, 1L<<0, close_win, fdf);
	fdf->data->img = mlx_new_image(fdf->mlx, 900, 800);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bits_per_pixel, &fdf->data->line_length,
								 &fdf->data->endian);
	comput_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img, 0, 0);
	mlx_loop(fdf->mlx);
}