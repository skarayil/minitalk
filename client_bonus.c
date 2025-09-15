/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:54:41 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/15 19:33:24 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(400);
}

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_send_bit(pid, (c >> i) & 1);
		i++;
	}
}

void	ft_send_string(int pid, char *str)
{
	while (*str)
	{
		ft_send_char(pid, *str);
		str++;
	}
	ft_send_char(pid, '\0');
}

void	ft_sig_handler(int signo, siginfo_t *siginfo, void *oact)
{
	static int	send_byte;

	(void)siginfo;
	(void)oact;
	if (signo == SIGUSR2)
	{
		ft_putstr("\r Send byte :");
		ft_putnbr(++send_byte);
	}
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sig;

	if (ac != 3)
	{
		ft_puterror("Usage: ./client <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1 || pid <= 0)
	{
		ft_puterror("Error: Invalid PID\n");
		return (1);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sig_handler;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_send_string(pid, av[2]);
	return (0);
}
