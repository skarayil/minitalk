/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:51:31 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/20 15:49:01 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"

int		ft_atoi(const char *str);
void	ft_putnbr(int nbr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif
