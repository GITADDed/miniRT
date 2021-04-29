/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:28:04 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 16:28:11 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*pointer;
	size_t		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	pointer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (pointer == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		*(pointer + i) = *s1;
		++i;
		++s1;
	}
	while (*s2)
	{
		*(pointer + i) = *s2;
		++i;
		++s2;
	}
	*(pointer + i) = '\0';
	return (pointer);
}
