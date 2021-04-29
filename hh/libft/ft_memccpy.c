/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:07:05 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 18:07:08 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	stop;
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	stop = (unsigned char)c;
	while (i < n)
	{
		if (*(temp_src + i) == stop)
		{
			*(temp_dest + i) = stop;
			return (temp_dest + i + 1);
		}
		*(temp_dest + i) = *(temp_src + i);
		++i;
	}
	return (0);
}
