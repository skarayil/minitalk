/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:59:50 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 20:47:34 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int signal)
{
	static int	bit;
	static int	byte;

	byte |= (signal == SIGUSR1) << bit;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
			ft_putchar_fd('\n', 1);
		bit = 0;
		byte = 0;
	}
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Usage: ./server\n", 2);
		return (1);
	}
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (42)
		;
	return (0);
}
