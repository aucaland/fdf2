/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:46:51 by aurel             #+#    #+#             */
/*   Updated: 2022/12/06 16:20:16 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_UTILS_H
#define FDF_DEFINE_UTILS_H

#include "fdf.h"

#define BLUE_F 0x0000ff
#define WHITE 0xffffff
#define RED_F 0xff0000
#define GREEN_F 0x00ff00

typedef struct s_col
{
	float range;
	//float max_coeff_reset;
	//float min_coeff_reset;
	enum e_MOD {neg, pos} mod;
}				t_col;

int	ft_gradient_colors(t_fdf *fdf);
void colors_range(t_fdf *fdf);

#endif //FDF_DEFINE_UTILS_H
