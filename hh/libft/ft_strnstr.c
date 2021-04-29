/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:22:06 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/28 13:22:10 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			my_string_compare(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (*str2 != '\0')
	{
		if (*str1 != *str2 || *str1 == '\0')
			return (i);
		++i;
		++str1;
		++str2;
	}
	return (-1);
}

char				*ft_strnstr(const char *src, const char *sough, size_t n_ch)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	len = ft_strlen(sough);
	if (*sough == '\0')
		return ((char *)src);
	if (n_ch == 0)
		return (0);
	while (*(src + i) != '\0' && i < n_ch)
	{
		if ((j = my_string_compare(src + i, sough)) == -1)
		{
			if ((i + len - 1) < n_ch)
				return ((char *)(src + i));
			else
				return (0);
		}
		++i;
	}
	return (0);
}
