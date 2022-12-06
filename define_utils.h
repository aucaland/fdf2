/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:46:51 by aurel             #+#    #+#             */
/*   Updated: 2022/12/06 18:20:34 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_UTILS_H
#define FDF_DEFINE_UTILS_H

# include "fdf.h"

typedef struct s_col
{
	float range;
	//float max_coeff_reset;
	//float min_coeff_reset;
	int isneg;
	int r;
	int g;
	int b;
}				t_col;
#define BLUE_F 0x0000ff
#define WHITE 0xffffff
#define RED_F 0xff0000
#define GREEN_F 0x00ff00

/*							Palette 					*/



#endif //FDF_DEFINE_UTILS_H
