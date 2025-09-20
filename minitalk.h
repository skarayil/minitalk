/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:51:31 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 20:51:02 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define SLEEP_TIME 300

int		ft_atoi(const char *str);
void	ft_putnbr(int nbr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif
