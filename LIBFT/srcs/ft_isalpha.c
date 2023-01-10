/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:45:59 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/07 19:37:23 by aucaland         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_islowcase(int str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	else
		return (0);
}

static int	ft_isuppercase(int str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (ft_islowcase(c) == 1 || ft_isuppercase(c) == 1)
		return (1);
	return (0);
}
