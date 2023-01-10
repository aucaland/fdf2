/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:34:20 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 11:29:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (i < n && (s1_c[i] || s2_c[i]))
	{
		if (s1_c[i] < s2_c[i])
			return (-1);
		else if (s1_c[i] > s2_c[i])
			return (1);
		i++;
	}
	return (0);
}
