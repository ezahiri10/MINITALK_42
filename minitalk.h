/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:49:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/21 11:11:08 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <limits.h>

long	ft_atoi(const char *s);
void	ft_putchar(char c, int fd);
void	ft_putnbr(long nb, int fd);
void	ft_putstr(char *s, int fd);
int		error_msg(char *s);

#endif
