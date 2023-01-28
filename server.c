/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:58:09 by mhirch            #+#    #+#             */
/*   Updated: 2023/01/28 16:44:25 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// char received_char;
// static void	signal_handler(int signum)
// {
// 	static int	bool = 1;
// 	if (signum == SIGUSR1)
// 	{
// 		// printf("1\n");
// 		bool = 0;
// 	}
// 	if (signum == SIGUSR2)
// 	{
// 		// printf("0\n");
// 		bool = 1;
// 		// exit (0);
// 	}
// 	printf("%d", bool);
// }
// static void	signal_handler(int signum)
// {
// 	int	bool = 0;
	
// 	if (signum == SIGUSR1)
// 	{
// 		bool = 1;
// 	}
// 	if (signum == SIGUSR2)
// 	{
// 		bool = 0;
// 	}
	
// }
// void signal_handler(int sig)
// {
//     if (sig == SIGUSR1)
//     {
//         received_char = (received_char << 1) | 1;
//     }
//     else if (sig == SIGUSR2)
//     {
//         received_char = received_char << 1;
//     }
// }

void signal_handler(int sig, siginfo_t *info, void *data)
{
    static int bit_counter;
    static char received_char;
	static pid_t pid_client;
	(void)data;

	if(pid_client != info->si_pid)
	{
		pid_client = info->si_pid;
		bit_counter = 0;
		received_char = 0;
	}
    if (sig == SIGUSR1)
    {
        received_char = (received_char << 1) | 1;
    }
    else if (sig == SIGUSR2)
    {
        received_char = received_char << 1;
    }

    bit_counter++;
    while (bit_counter == 8)
    {
        // printf("%c", received_char);
		write(1, &received_char, 1);
        bit_counter = 0;
        received_char = 0;
    }
}


int	main(int ac, char **av)
{
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if ( ac == 1 && av[0])
	{
		ft_putstr("server's PID is : ");
		ft_putnbr(getpid());
		write(1, "\n", 1);
		//signal(SIGUSR1, signal_handler);
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		//signal(SIGUSR2, signal_handler);
		// printf("%c", received_char);
		while (1)
			pause();
	}
	else
		ft_putstr("Error\n");
}
