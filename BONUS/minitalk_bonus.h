/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:49:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/23 12:37:45 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <limits.h>

typedef struct s_object
{
	int		c;
	int		i;
	pid_t	id_send;
	char	str[4];
	int		b;
	int		x;
}	t_object;

long	ft_atoi(const char *s);
void	ft_putchar(char c, int fd);
void	ft_putnbr(long nb, int fd);
void	ft_putstr(char *s, int fd);
int		error_msg(char *s);

#endif
