/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:50 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/02 13:52:52 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(t_list **list, void (*del)(void *))
{
	ft_lstclear(list, del);
	return (0);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list *new_list;
	t_list *node;

	if (lst == 0)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	if (new_list == 0)
		return (0);
	lst = lst->next;
	while (lst != 0)
	{
		node = ft_lstnew(f(lst->content));
		if (node == 0)
			return (ft_free(&new_list, del));
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
