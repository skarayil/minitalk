/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:59:50 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 19:31:06 by skarayil         ###   ########.fr       */
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
		ft_putchar(byte);
		if (byte == '\0')
			ft_putchar('\n');
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
		ft_puterror("Usage: ./server\n");
		return (1);
	}
	ft_putstr("╔══════════════════════════════════╗\n");
	ft_putstr("║      MINITALK BONUS SERVER       ║\n");
	ft_putstr("╚══════════════════════════════════╝\n\n");
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n\n");
	sig.sa_sigaction = ft_signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (42)
		;
	return (0);
}
