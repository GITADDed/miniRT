/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:45:25 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 16:45:29 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_chrcmp(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (0);
		set++;
	}
	return (-1);
}

static size_t	id_front(char const *set, char const *str)
{
	size_t i;

	i = 0;
	while (*str != '\0' && ft_chrcmp(*str, set) == 0)
	{
		i++;
		str++;
	}
	return (i);
}

static size_t	id_back(char const *set, char const *str, size_t len, size_t s)
{
	while (ft_chrcmp(*(str + len - 1), set) == 0 && s != len)
		len--;
	return (len - 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		finish;
	size_t		start;
	char		*pointer;
	size_t		i;

	if (s1 == 0)
		return (0);
	if (set == 0 || *set == '\0' || *s1 == '\0')
		return ((char *)s1);
	start = id_front(set, s1);
	finish = id_back(set, s1, ft_strlen(s1), start);
	pointer = malloc((finish - start + 2) * sizeof(char));
	if (pointer == 0)
		return (0);
	i = 0;
	while (start <= finish)
	{
		*(pointer + i) = *(s1 + start);
		i++;
		start++;
	}
	*(pointer + i) = '\0';
	return (pointer);
}
