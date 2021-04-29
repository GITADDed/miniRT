/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:38:16 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 14:38:19 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*temp_dest;
	char		*temp_src;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (i < n)
	{
		*(temp_dest + i) = *(temp_src + i);
		++i;
	}
	return (dest);
}
