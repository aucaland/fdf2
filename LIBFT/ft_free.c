/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:17:33 by aurel             #+#    #+#             */
/*   Updated: 2022/12/03 12:31:09 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TODO: verif if valid
void ft_free(void *ptr, int size)
{
	if (size > 0)
	{
		while (ptr && size > 0)
		{
			free(ptr);
			ptr = NULL;
			ptr++;
			size--;
		}
	}
	else
	{
		free(ptr);
		ptr = NULL;
	}
}
