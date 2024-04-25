/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:48:42 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/25 22:28:49 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static long	ft_atoi(const char *s)
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

static void	send_message(char c, int id)
{
	int		bit;
	int		i;

	i = 0;
	bit = 128;
	while (i < 8)
	{
		if (c & bit)
		{
			if (kill(id, SIGUSR1) == -1)
				error_msg ("kill : No such process");
		}
		else
		{
			if (kill(id, SIGUSR2) == -1)
				error_msg ("kill: No such process");
		}
		c <<= 1;
		i++;
		usleep(500);
	}
}

static void	ft_handler(int sig)
{
	(void)sig;
	ft_putstr ("your message Recieaved\n", 1);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	id;

	i = -1;
	if (ac != 3)
		error_msg ("arguments not fount");
	id = ft_atoi(av[1]);
	if (id <= 1)
	{
		ft_putstr("kill: illegal pid : ", 2);
		error_msg(av[1]);
	}
	while (av[2][++i])
		send_message (av[2][i], id);
	signal(SIGUSR1, ft_handler);
	send_message ('\0', id);
	return (0);
}
