/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:46:51 by aurel             #+#    #+#             */
/*   Updated: 2022/12/08 12:15:57 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_UTILS_H
#define FDF_DEFINE_UTILS_H

# include "fdf.h"

typedef struct s_col
{
	int pal[10];
	int pal2[10];
	int palr[10];
	int pal3[10];
}				t_col;

#define BLUE_F 0x0000ff
#define WHITE 0xffffff
#define RED_F 0xff0000
#define GREEN_F 0x00ff00
/*							PALETTES					*/
/*	1			HYPERCHILL				*/

# define	P0_1 0xffb845
# define	P0_2 0xfb7974
# define	P0_3 0xf97698
# define	P0_4 0xce5f9f
# define	P0_5 0xa348a6
# define	P0_6 0x8549ad
# define	P0_7 0x674ab3
# define	P0_8 0x556dc8
# define	P0_9 0x6783db
# define	P0_10 0x7998ee

/* 	2			NEON_SPACE					*/

# define P1_1 0xdf0772
# define P1_2 0xfe546f
# define P1_3 0xff9e7d
# define P1_4 0xffd080
# define P1_5 0xfffdff
# define P1_6 0x0bffe6
# define P1_7 0x01cbcf
# define P1_8 0x0188a5
# define P1_9 0x3e3264
# define P1_10 0x352a55


# define P2_1 0xF7F6CF
# define P2_2 0xB6D8F2
# define P2_3 0xF4CFDF
# define P2_4 0x5784BA
# define P2_5 0x9AC8EB
# define P2_6 0xF08488
# define P2_7 0xFF9CB6
# define P2_8 0xFFD0E6
# define P2_9 0xC49FFF
# define P2_10 0x7D4FFE


# define HEX "0123456789abcdef"

#endif //FDF_DEFINE_UTILS_H
