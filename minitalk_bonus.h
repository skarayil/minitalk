/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:51:31 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 20:13:16 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define CYAN    "\033[0;36m"
# define RED     "\033[0;31m"
# define RESET   "\033[0m"

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterr(char *err);
int		ft_atoi(const char *str);

#endif
