/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:33:44 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 15:33:47 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*pointer;

	if (s == 0)
		return (0);
	pointer = malloc((len + 1) * sizeof(char));
	if (pointer == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (pointer);
	i = 0;
	while (*(s + start + i) && i < len)
	{
		*(pointer + i) = *(s + start + i);
		++i;
	}
	*(pointer + i) = '\0';
	return (pointer);
}
