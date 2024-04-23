/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:49:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/23 15:33:02 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

long	ft_atoi(const char *s);
void	ft_putchar(char c, int fd);
void	ft_putnbr(long nb, int fd);
void	ft_putstr(char *s, int fd);
int		error_msg(char *s);

#endif
