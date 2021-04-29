/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:36:37 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/31 17:36:39 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char			**new_ptr(const char *s, char c)
{
	size_t		i;
	char		**ptr;

	i = 1;
	while (*s != '\0')
	{
		if (*s != c && *(s + 1) == c)
			i++;
		s++;
	}
	ptr = (char **)malloc(sizeof(char *) * (i + 1));
	if (ptr == 0)
		return (0);
	ptr[i] = 0;
	return (ptr);
}

static	char			*ft_new_word(const char **s, char c)
{
	size_t		i;
	char		*str;

	i = 0;
	while (*(*s + i) != c && *(*s + i) != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (**s != c && **s != '\0')
	{
		*(str + i) = **s;
		(*s)++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

static void				*ft_free(char **ptr)
{
	while (*ptr != 0)
	{
		free(*ptr);
		ptr++;
	}
	return (0);
}

char					**ft_split(char const *s, char c)
{
	char		**ptr;
	size_t		ln_ptr_arr;

	if (s == 0)
		return (0);
	ln_ptr_arr = 0;
	if ((ptr = new_ptr(s, c)) == 0)
		return (0);
	while (*s != '\0')
	{
		if (*s != c)
			ptr[ln_ptr_arr++] = ft_new_word(&s, c);
		if (ln_ptr_arr > 0 && ptr[ln_ptr_arr - 1] == 0)
			return (ft_free(ptr));
		if (*s == '\0')
			break ;
		s++;
	}
	ptr[ln_ptr_arr] = 0;
	return (ptr);
}
