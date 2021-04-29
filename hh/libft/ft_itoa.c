/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:28:13 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/01 17:28:16 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			push_right_to_left(char **string, char c, int position)
{
	char *temp_str;

	temp_str = *string;
	*(temp_str + position) = c;
}

static int			len_num(int n)
{
	int ans;

	ans = 0;
	while (n != 0)
	{
		ans++;
		n /= 10;
	}
	return (ans);
}

static void			init_digit(char digits[11])
{
	int i;

	i = 0;
	while (i < 10)
	{
		digits[i] = '0' + i;
		i++;
	}
}

char				*ft_itoa(int n)
{
	char		*answer;
	char		digits[11];
	long		temp_n;
	int			k;

	init_digit(digits);
	k = 1;
	temp_n = n;
	if (temp_n < 0)
	{
		temp_n *= -1;
		k = 0;
	}
	if ((answer = ft_calloc(len_num(temp_n) + 2, sizeof(char))) == 0)
		return (0);
	if (temp_n == 0)
		push_right_to_left(&answer, '0', 0);
	while (temp_n != 0)
	{
		push_right_to_left(&answer, digits[temp_n % 10], len_num(temp_n) - k);
		temp_n /= 10;
	}
	if (k == 0)
		push_right_to_left(&answer, '-', 0);
	return (answer);
}
