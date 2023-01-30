/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:07:03 by aurel             #+#    #+#             */
/*   Updated: 2023/01/30 10:14:32 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
