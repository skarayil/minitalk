/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:16:36 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/18 08:04:54 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ft_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
	}
}

void	ft_send_string(int pid, char *str)
{
	int	send_byte;

	send_byte = 0;
	while (*str)
	{
		ft_send_char(pid, *str);
		send_byte++;
		if (send_byte % 100 == 0)
		{
			ft_putstr_fd("\r\033[K" MAGENTA "Sent Bytes: " RESET, 1);
			ft_putnbr(send_byte);
		}
		str++;
	}
	ft_send_char(pid, '\0');
	send_byte++;
	ft_putstr_fd("\r\033[K" MAGENTA "Sent Bytes: " RESET, 1);
	ft_putnbr(send_byte);
	ft_putchar_fd('\n', 1);
}

static int	ft_validate(int ac, char *av[], pid_t *pid)
{
	if (ac != 3)
	{
		ft_putstr_fd(RED "Usage: ./client <PID> <message>\n" RESET, 2);
		return (1);
	}
	*pid = ft_atoi(av[1]);
	if (kill(*pid, 0) == -1 || *pid <= 0)
	{
		ft_putstr_fd(RED "Invalid PID!\n" RESET, 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sig;

	if (ft_validate(ac, av, &pid))
		return (1);
	ft_putstr_fd(MAGENTA "Client PID: " RESET, 1);
	ft_putnbr(getpid());
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(MAGENTA "Server PID: " RESET, 1);
	ft_putnbr(pid);
	ft_putchar_fd('\n', 1);
	sig.sa_handler = ft_ack_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_send_string(pid, av[2]);
	ft_putstr_fd(MAGENTA "\nMessage delivered!\n" RESET, 1);
	return (0);
}
