/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:20:19 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/16 01:49:40 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_print_message(int message_count)
{
	ft_putstr_fd(CYAN "\nMessage #", 1);
	ft_putnbr(message_count);
	ft_putstr_fd(CYAN " received successfully!\n" RESET, 1);
	ft_putstr_fd("────────────────────────────────────\n\n", 1);
}

void	ft_handle_client(siginfo_t *siginfo, int *message_count)
{
	(void)siginfo;
	(*message_count)++;
}

void	ft_signal_handler(int signo, siginfo_t *siginfo, void *oact)
{
	static int		bit;
	static char		byte;
	static pid_t	pid;
	static int		message_count;

	(void)oact;
	if (!pid || pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		bit = 0;
		byte = 0;
		ft_handle_client(siginfo, &message_count);
	}
	byte |= (signo == SIGUSR1) << bit;
	bit++;
	if (bit == 8)
	{
		if (byte != '\0')
			ft_putchar_fd(byte, 1);
		else
			ft_print_message(message_count);
		bit = 0;
		byte = 0;
		kill(pid, SIGUSR2);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sig;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd(RED "Usage: ./server\n" RESET, 2);
		return (1);
	}
	ft_putstr_fd(CYAN "╔═════════════════════════╗\n" RESET, 1);
	ft_putstr_fd(CYAN "║  MINITALK BONUS SERVER  ║\n" RESET, 1);
	ft_putstr_fd(CYAN "╚═════════════════════════╝\n\n" RESET, 1);
	ft_putstr_fd(CYAN "Server PID: " RESET, 1);
	ft_putnbr(getpid());
	ft_putstr_fd(CYAN "\nWaiting for messages...\n\n" RESET, 1);
	sig.sa_sigaction = ft_signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (42)
		pause();
	return (0);
}
