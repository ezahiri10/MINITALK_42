/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:07:55 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/24 12:13:49 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*(unsigned char *)(b + len) = (unsigned char )c;
	return (b);
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
