/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:59:50 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 20:49:59 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_signal_handler(int signo, siginfo_t *siginfo, void *oact)
{
	static int		bit;
	static char		byte;
	static pid_t	pid;

	(void)oact;
	if (!pid || pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		bit = 0;
		byte = 0;
	}
	byte |= (signo == SIGUSR1) << bit;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
			ft_putchar_fd('\n', 1);
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
	ft_putstr_fd(CYAN "╔══════════════════════════════════╗\n" RESET, 1);
	ft_putstr_fd(CYAN "║      MINITALK BONUS SERVER       ║\n" RESET, 1);
	ft_putstr_fd(CYAN "╚══════════════════════════════════╝\n\n" RESET, 1);
	ft_putstr_fd(CYAN "Server PID: " RESET, 1);
	ft_putnbr(getpid());
	ft_putstr_fd("\n\n", 1);
	sig.sa_sigaction = ft_signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (42)
		;
	return (0);
}
