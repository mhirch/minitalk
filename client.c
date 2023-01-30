/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:59:45 by mhirch            #+#    #+#             */
/*   Updated: 2023/01/30 19:46:35 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
		i--;
	}
}

void	say_done(int i)
{
	if (i == SIGUSR1)
		write(1, "\033[0;34mmessage received by the server\n\033[0m", 38);
}

int	main(int ac, char **av)
{
	int		pid;
	size_t	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "\033[0;31mError:\033[0m pid is incorrect\n", 36);
			return (1);
		}
		signal(SIGUSR1, say_done);
		while (ft_strlen(av[2]) >= i)
			char_to_binary(pid, av[2][i++]);
	}
	else
		write(1, "\033[0;31mError:\033[0m too many or few arguments\n", 45);
}
