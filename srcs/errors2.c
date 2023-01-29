/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:07:03 by aurel             #+#    #+#             */
/*   Updated: 2023/01/29 18:49:54 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

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

void	free_menu(t_fdf *fdf)
{
	if (fdf->str)
		free(fdf->str);
	fdf->str = NULL;
	if (fdf->col.str2)
		free(fdf->col.str2);
	fdf->col.str2 = NULL;
	if (fdf->col.str1)
		free(fdf->col.str1);
	fdf->col.str1 = NULL;
	if (fdf->col.r)
		free(fdf->col.r);
	fdf->col.r = NULL;
	if (fdf->col.g)
		free(fdf->col.g);
	fdf->col.g = NULL;
	if (fdf->col.b)
		free(fdf->col.b);
	fdf->col.b = NULL;
}