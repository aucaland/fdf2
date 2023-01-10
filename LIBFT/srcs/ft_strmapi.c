/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:16:34 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/14 17:28:43 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_c;
	int				len_s;

	i = 0;
	str_c = NULL;
	if (s && f)
	{
		len_s = ft_strlen(s);
		str_c = malloc(sizeof(char) * len_s + 1);
		if (!str_c)
			return (NULL);
		str_c[len_s] = '\0';
		while (s[i])
		{
			str_c[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (str_c);
}
