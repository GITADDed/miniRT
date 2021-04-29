/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:17:17 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 13:17:19 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char		*pointer;

	pointer = (char *)malloc(count * size);
	if (pointer == 0)
		return (0);
	ft_bzero(pointer, count * size);
	return ((void *)pointer);
}
