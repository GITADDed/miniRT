/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:51:45 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/02 13:51:47 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *node;

	node = *lst;
	if (node != 0)
	{
		while (node->next != 0)
			node = node->next;
		node->next = new;
	}
	else
		*lst = new;
}
