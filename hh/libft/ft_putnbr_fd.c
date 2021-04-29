/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenyatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:39:29 by tzenyatt          #+#    #+#             */
/*   Updated: 2020/11/01 20:39:31 by tzenyatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

static int			ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void				ft_putnbr_fd(int n, int fd)
{
	char		digits[11];
	int			num[12];
	int			i;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	init_digit(digits);
	if (n < 0)
		write(fd, "-", 1);
	while (n != 0)
	{
		num[i] = ft_abs(n % 10);
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &digits[num[i]], 1);
		i--;
	}
}
