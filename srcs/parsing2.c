/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:21:17 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/10 14:21:17 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_map_z(t_fdf *fdf, int nbr_word, char *list_content, int i)
{
	int	j;

	j = 0;
	while (j < nbr_word)
	{
		while (*list_content != '\0' && ft_isspace(*list_content))
			list_content++;
		fdf->map->tab[i][j] = ft_atoi((list_content));
		fdf->map->max_coeff = fmax(fdf->map->max_coeff, \
			fdf->map->tab[i][j]);
		fdf->map->min_coeff = fmin(fdf->map->min_coeff, \
			fdf->map->tab[i][j++]);
		while (*list_content != '\0' && !ft_isspace(*list_content))
			list_content++;
	}
}
