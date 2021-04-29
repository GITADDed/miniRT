/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:27:40 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 19:27:42 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*temp_dest;
	char		*temp_src;
	size_t		i;

	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (temp_src > temp_dest)
	{
		i = 0;
		while (i < len)
		{
			*(temp_dest + i) = *(temp_src + i);
			++i;
		}
	}
	else if (temp_dest != temp_src)
	{
		i = len;
		while (i > 0)
		{
			*(temp_dest + i - 1) = *(temp_src + i - 1);
			--i;
		}
	}
	return (dest);
}
