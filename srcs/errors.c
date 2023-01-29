/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:30:04 by aurel             #+#    #+#             */
/*   Updated: 2023/01/29 02:51:48 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	exit_fdf(t_fdf *fdf, char *err, char *location, int state)
{
	if (state == 1)
	{
		ft_putstr_fd(err, 2);
		ft_putendl_fd(location, 2);
		exit(0);
	}
	else if (ft_strlen(err) > 0 && ft_strncmp(err, PERROR, 6) == 0)
		perror(location);
	else if (ft_strlen(err) > 0)
	{
		ft_putstr_fd(err, 2);
		ft_putendl_fd(location, 2);
	}
	ft_free_fdf(fdf, state);
}

void	ft_free_fdf(t_fdf *fdf, int state)
{
	if (state == 1)
	{
		if (fdf->map->tab)
			ft_freetabi(&fdf->map->tab, fdf->map->nbr_line);
		if (fdf->cam->h_on == 1)
			mlx_destroy_image(fdf->mlx, fdf->data->img2);
		if (fdf->data->img)
		{
			mlx_destroy_image(fdf->mlx, fdf->data->img);
			mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		}
	}
	if (fdf->data)
		ft_free(fdf->data);
	if (fdf->cam)
		ft_free(fdf->cam);
	if (fdf->map)
		ft_free(fdf->map);
	ft_free(fdf);
	exit(EXIT_SUCCESS);
}

void	protect_alloc(t_fdf *fdf, void *ptr, void *ptr_two, char *location)
{
	if (ptr)
		return ;
	if (ptr_two)
		free(ptr_two);
	exit_fdf(fdf, MALLOC_ERR, location, 0);
}

void	protect_alloc_list(t_fdf *fdf, void *ptr, void **ptr_two, char *location)
{
	if (ptr)
		return ;
	ft_lstclear((t_list**)ptr_two, free);
	exit_fdf(fdf, MALLOC_ERR, location, 0);
}