/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:46:51 by aurel             #+#    #+#             */
/*   Updated: 2022/12/07 12:41:46 by aucaland         ###   ########.fr       */
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
	float r;
	float g;
	float b;
	float range_r;
	float range_g;
	float range_b;

}				t_col;

#define BLUE_F 0x0000ff
#define WHITE 0xffffff
#define RED_F 0xff0000
#define GREEN_F 0x00ff00

# define	CAM 0xa67c00
# define	PURP 0xa67c00
# define	PURPL 0xa67c00
# define	GRP 0x05878a
# define	 BEIGE 0xbe9b7b

/*							Palette 					*/



#endif //FDF_DEFINE_UTILS_H
