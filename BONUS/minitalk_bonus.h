/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:49:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/27 17:04:16 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_object
{
	int		c;
	int		i;
	pid_t	id_send;
	char	str[4];
	int		b;
	int		x;
}	t_object;

void	ft_putchar(char c, int fd);
void	ft_putnbr(long nb, int fd);
void	ft_putstr(char *s, int fd);
int		error_msg(char *s);
void	*ft_memset(void *b, int c, size_t len);

#endif
