/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:35:56 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/23 11:28:14 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_write(t_object	*obj)
{
	if (obj->c >= 0 && obj->c <= 127)
	{
		write(1, &obj->c, 1);
		return ;
	}
	if (obj->c >= 192 && obj->c <= 223)
		obj->b = 2;
	else if (obj->c >= 224 && obj->c <= 239)
		obj->b = 3;
	else if (obj->c >= 240 && obj->c <= 244)
		obj->b = 4;
	obj->str[obj->x++] = obj->c;
	if (obj->x == obj->b)
	{
		ft_putstr(obj->str, 1);
		obj->b = 0;
		obj->x = 0;
		memset(obj->str, 0, 4);
	}
}

static void	_handler(int sig_num, siginfo_t *sig, void *none)
{
	static t_object	obj;
	static int		cpt = 128;

	(void)none;
	if (obj.id_send != sig->si_pid)
	{
		memset(&obj, 0, sizeof(obj));
		cpt = 128;
	}
	if (sig_num == SIGUSR1)
		obj.c += cpt;
	cpt /= 2;
	obj.i++;
	if (obj.i == 8)
	{
		if (obj.c == '\0')
			kill (sig->si_pid, SIGUSR1);
		ft_write(&obj);
		obj.c = 0;
		obj.i = 0;
		cpt = 128;
	}
	obj.id_send = sig->si_pid;
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
