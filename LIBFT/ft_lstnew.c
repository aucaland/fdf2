/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:00:04 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/14 00:24:24 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*np;

	np = malloc(sizeof(t_list));
	if (np)
	{
		np->content = content;
		np->next = NULL;
	}
	else
		np = NULL;
	return (np);
}
