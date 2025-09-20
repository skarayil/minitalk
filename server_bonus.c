/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:15:01 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/20 15:51:48 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <signal.h>
#include <unistd.h>

void	ft_print_message(int message_count, int client)
{
	ft_putstr_fd(CYAN "\nMessage #", 1);
	ft_putnbr(message_count);
	ft_putstr_fd(" received successfully!\n" RESET, 1);
	ft_putstr_fd(CYAN "From Client PID: " RESET, 1);
	ft_putnbr(client);
	ft_putstr_fd(RESET "\n", 1);
	ft_putstr_fd("────────────────────────────────────\n\n" RESET, 1);
}

static void	ft_change_client(int *client_pid, int current_pid)
{
	if (*client_pid != current_pid)
	{
		*client_pid = current_pid;
	}
}

static void	ft_process_byte(unsigned char *byte, int *bit, int *client_pid,
		int *message_count)
{
	if (*byte == '\0')
	{
		ft_putstr_fd(RESET, 1);
		(*message_count)++;
		ft_print_message(*message_count, *client_pid);
		write(1, "\n", 1);
		kill(*client_pid, SIGUSR2);
		*client_pid = 0;
	}
	else
		write(1, byte, 1);
	*bit = 0;
	*byte = 0;
}

void	ft_signal_handler(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	byte;
	static int				bit;
	static int				client_pid;
	static int				message_count;

	(void)context;
	ft_change_client(&client_pid, siginfo->si_pid);
	byte <<= 1;
	if (signo == SIGUSR1)
		byte |= 1;
	if (++bit == 8)
		ft_process_byte(&byte, &bit, &client_pid, &message_count);
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
	while (42)
		pause();
	return (0);
}
