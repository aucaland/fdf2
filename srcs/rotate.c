/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:20 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/06 09:30:56 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

void ft_rotate_x(float *y, int *z, double alpha)
{
	float previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}