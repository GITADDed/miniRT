/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:34:20 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/30 22:34:24 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char		*pdst;
	const char		*psrc;
	size_t			n;
	size_t			dlen;

	pdst = dst;
	psrc = src;
	n = dsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - pdst;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - psrc));
}
