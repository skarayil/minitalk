/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:15:01 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/18 07:53:01 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_print_message(int message_count, int sender_pid)
{
	ft_putstr_fd(CYAN "\nMessage #", 1);
	ft_putnbr(message_count);
	ft_putstr_fd(CYAN " received successfully!\n" RESET, 1);
	ft_putstr_fd(CYAN "From Client PID: ", 1);
	ft_putnbr(sender_pid);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("────────────────────────────────────\n\n", 1);
}

static void	ft_change_client(int *client_pid, int sig_pid)
{
	if (*client_pid != sig_pid)
	{
		*client_pid = sig_pid;
	}
}

static void	ft_process_byte(unsigned char *c, int *bit, int *client_pid,
		int *message_count)
{
	if (*c == '\0')
	{
		(*message_count)++;
		ft_print_message(*message_count, *client_pid);
		write(1, "\n", 1);
		kill(*client_pid, SIGUSR2);
		*client_pid = 0;
	}
	else
		write(1, c, 1);
	*bit = 0;
	*c = 0;
}

void	ft_signal_handler(int signo, siginfo_t *siginfo, void *oact)
{
	static unsigned char	c;
	static int				bit;
	static int				client_pid;
	static int				message_count;

	(void)oact;
	ft_change_client(&client_pid, siginfo->si_pid);
	c <<= 1;
	if (signo == SIGUSR1)
		c |= 1;
	if (++bit == 8)
		ft_process_byte(&c, &bit, &client_pid, &message_count);
	kill(siginfo->si_pid, SIGUSR1);
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
	while (1)
		pause();
	return (0);
}
