/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:57:08 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 21:57:11 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t i;
	size_t s;

	if (dest == 0 && src == 0)
		return (0);
	s = ft_strlen(src);
	if (destsize == 0)
		return (s);
	i = 0;
	while (i < destsize - 1 && *(src + i))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = '\0';
	return (s);
}
