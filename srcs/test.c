/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:35 by aurel             #+#    #+#             */
/*   Updated: 2022/12/03 21:19:55 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (fdf);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_fdf	*fdf;

	fdf = init_struct_main();
	parsing(argv[1], fdf);

//	fdf->mlx = mlx_init();
//	fdf->mlx_win = mlx_new_window(fdf->mlx, 800, 800, "Hello ok");
//	mlx_hook(fdf->mlx_win, 2, 1L<<0, close_win, fdf);
//	fdf->data->img = mlx_new_image(fdf->mlx, 800, 800);
//	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bits_per_pixel, &fdf->data->line_length,
//								 &fdf->data->endian);
//	my_mlx_pixel_put(fdf->data, 50, 50, 0x00FF0000);
//	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->data->img, 0, 0);
//	mlx_loop(fdf->mlx);
}