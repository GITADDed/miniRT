/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:33:12 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 13:33:14 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	char		*pointer;
	size_t		len_s1;

	len_s1 = ft_strlen(s1);
	pointer = (char *)ft_calloc(len_s1 + 1, sizeof(char));
	if (pointer == 0)
	{
		errno = ENOMEM;
		return (0);
	}
	len_s1 = 0;
	while (*(s1 + len_s1))
	{
		*(pointer + len_s1) = *(s1 + len_s1);
		++len_s1;
	}
	return (pointer);
}
