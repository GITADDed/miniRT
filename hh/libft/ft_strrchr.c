/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:47:21 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/10/28 11:47:27 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	char *answ;

	answ = 0;
	while (*str != '\0')
	{
		if (*str == ch)
			answ = (char *)str;
		++str;
	}
	if (*(str) == ch)
		return ((char *)str);
	return (answ);
}
