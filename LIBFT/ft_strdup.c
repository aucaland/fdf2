/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:02:16 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 13:43:14 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;
	int		len_src;

	i = 0;
	len_src = 0;
	while (s1[len_src])
		len_src++;
	tab = malloc(sizeof(char) * (len_src + 1));
	if (!tab)
		return (NULL);
	tab[len_src] = '\0';
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	return (tab);
}
