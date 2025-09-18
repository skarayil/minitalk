/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:54:41 by skarayil          #+#    #+#             */
/*   Updated: 2025/09/18 07:53:13 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
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

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client <PID> <message>\n", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1 || pid <= 0)
	{
		ft_putstr_fd("err: Invalid PID\n", 2);
		return (1);
	}
	ft_send_string(pid, av[2]);
	return (0);
}
