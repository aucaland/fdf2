/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:18:03 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 13:56:11 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_dst(char *dst, char *s1_c, char *s2_c)
{
	int	len_s1;
	int	len_s2;

	len_s2 = 0;
	len_s1 = 0;
	while (s1_c[len_s1])
	{
		dst[len_s1] = s1_c[len_s1];
		len_s1++;
	}
	while (s2_c[len_s2])
	{
		dst[len_s1] = s2_c[len_s2];
		len_s2++;
		len_s1++;
	}
	dst[len_s1] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len_s1;
	int		len_s2;
	char	*s1_c;
	char	*s2_c;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	s1_c = (char *)s1;
	s2_c = (char *)s2;
	while (s1_c[len_s1])
		len_s1++;
	while (s2_c[len_s2])
		len_s2++;
	dst = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!dst)
		return (NULL);
	fill_dst(dst, s1_c, s2_c);
	return (dst);
}
