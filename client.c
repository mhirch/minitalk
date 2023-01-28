/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:59:45 by mhirch            #+#    #+#             */
/*   Updated: 2023/01/28 16:24:31 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void char_to_binary(int pid,char c)
{
    int i;
    
    i = 7;
    while(i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(250);
        i--;
    }
}

int main(int ac, char **av)
{
    int pid;
    size_t i;

    i = 0;
    if (ac == 3)
    {
        printf("Client pid : %d\n", getpid());
        pid = ft_atoi(av[1]);
        while(ft_strlen(av[2]) > i)
        
            char_to_binary(pid,av[2][i++]);
    }
}

