/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:06:43 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/01 20:06:46 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*answ;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	answ = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (answ == 0)
		return (0);
	while (*(s + i))
	{
		*(answ + i) = f(i, *(s + i));
		++i;
	}
	*(answ + i) = '\0';
	return (answ);
}
