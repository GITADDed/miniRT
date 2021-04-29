/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:16:29 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/29 21:16:34 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char		*temp_b;
	size_t		i;

	i = 0;
	temp_b = (char *)b;
	while (i < len)
	{
		*temp_b = c;
		++temp_b;
		++i;
	}
	return (b);
}
