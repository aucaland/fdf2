/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:45 by aurel             #+#    #+#             */
/*   Updated: 2022/12/04 23:10:13 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hook(int keycode, t_fdf *fdf)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	if (keycode == 65451)

	if (keycode == 65453)
		--
	return (0);
}
