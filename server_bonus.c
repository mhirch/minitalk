/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:53:01 by mhirch            #+#    #+#             */
/*   Updated: 2023/02/01 16:02:06 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static	void	process_bits(int *bit_counter, \
	char *received_char, pid_t *pid_client)
{
	if (*bit_counter == 8)
	{
		if (!*received_char)
		{
			kill(*pid_client, SIGUSR1);
			*pid_client = 0;
			return ;
		}
		write(1, received_char, 1);
		*bit_counter = 0;
		*received_char = 0;
	}
}

static	void	signal_handler(int sig, siginfo_t *info, void *data)
{
	static int		bit_counter;
	static char		received_char;
	static pid_t	pid_client;

	(void)data;
	if (pid_client != info->si_pid)
	{
		pid_client = info->si_pid;
		bit_counter = 0;
		received_char = 0;
	}
	if (sig == SIGUSR1)
		received_char = (received_char << 1) | 1;
	else if (sig == SIGUSR2)
		received_char = received_char << 1;
	bit_counter++;
	process_bits(&bit_counter, &received_char, &pid_client);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (ac == 1 && av[0])
	{
		ft_putstr("server's PID is : ");
		ft_putnbr(getpid());
		write(1, "\n", 1);
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		while (1)
			pause();
	}
	else
		ft_putstr("Error\n");
}
