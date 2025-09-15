/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:59:50 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 14:12:42 by skarayil         ###   ########.fr       */
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
		ft_putchar(byte);
		if (byte == '\0')
			ft_putchar('\n');
		bit = 0;
		byte = 0;
	}
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr("Usage: ./server\n");
		return (1);
	}
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (42)
		;
	return (0);
}