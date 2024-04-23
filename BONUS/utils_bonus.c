/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:07:55 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/23 11:36:43 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

long	ft_atoi(const char *s)
{
	long	r;

	r = 0;
	if (!*s)
		return (-1);
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			r = r * 10 + *s - 48;
			if (r > 2147483647 || r < -2147483648)
				return (-1);
			s++;
		}
		else
			return (-1);
	}
	return (r);
}

void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i], fd);
}

void	ft_putnbr(long nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr(-nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	else
		ft_putchar(nb + 48, fd);
}

int	error_msg(char *s)
{
	ft_putstr(s, 2);
	exit(1);
}
