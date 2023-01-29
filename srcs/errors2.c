/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:07:03 by aurel             #+#    #+#             */
/*   Updated: 2023/01/29 17:08:49 by aurel            ###   ########.fr       */
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

void	free_menu(t_fdf *fdf, char *str, char *str1, char *str2)
{
	free(str);
	str = NULL;
	free(str2);
	str2 = NULL;
	free(str1);
	str1 = NULL;
	free(fdf->col.r);
	fdf->col.r = NULL;
	free(fdf->col.g);
	fdf->col.g = NULL;
	free(fdf->col.b);
	fdf->col.b = NULL;
}