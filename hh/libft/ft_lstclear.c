/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:18 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/02 13:52:20 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;
	t_list *node1;

	if (lst == 0)
		return ;
	node = *lst;
	while (node != 0)
	{
		node1 = node->next;
		del(node->content);
		free(node);
		node = node1;
	}
	*lst = 0;
}
