/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:35:56 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/21 15:08:02 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	_handler(int sig_num, siginfo_t *sig, void *none)
{
	static int		c;
	static int		cpt = 128;
	static int		i;
	static pid_t	id_send;

	(void)none;
	if (id_send != sig->si_pid)
	{
		c = 0;
		i = 0;
		cpt = 0;
	}
	if (sig_num == SIGUSR1)
		c += cpt;
	cpt /= 2;
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		c = 0;
		i = 0;
		cpt = 128;
	}
	id_send = sig->si_pid;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		error_msg("error in number of argument");
	ft_putstr("pid of serever is :    ", 1);
	ft_putnbr (getpid(), 1);
	ft_putchar('\n', 1);
	sa.sa_sigaction = _handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	else if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	while (1)
		;
	return (0);
}
