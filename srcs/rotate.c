/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:20 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/05 16:09:44 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

void ft_rotate_x(t_fdf *fdf, double alpha)
{
	int previous_y;
	double *x;
	double *y;

	x = &fdf->map->
	x = &fdf->rot->rot_x
	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}