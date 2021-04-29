/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:39:58 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 20:40:02 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*temp_s;
	size_t		i;

	i = 0;
	temp_s = (char *)s;
	while (i < n)
	{
		if (*(temp_s + i) == c)
			return (temp_s + i);
		++i;
	}
	return (0);
}
