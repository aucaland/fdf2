/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:20 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/06 13:14:18 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

void ft_rotate_x(float *y, int *z, double rot_x)
{
	float old_y;

	old_y = *y;
	*y = old_y * cos(rot_x) + *z * sin(rot_x);
	*z = -old_y * sin(rot_x) + *z * cos(rot_x);
}

void ft_rotate_y(float *x, int *z, double rot_y)
{
	float old_x;
	old_x = *x;

	*x = old_x * cos(rot_y) - *z * sin(rot_y);
	*z = old_x * sin(rot_y) + *z * cos(rot_y);
}

void ft_rotate_z(float *x, float *y, double rot_z)
{
	float old_x;
	float old_y;
	old_x = *x;
	old_y = *y;

	*x = old_x * cos(rot_z) + old_y * sin(rot_z);
	*y = -old_x * sin(rot_z) + old_y * cos(rot_z);
}