/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:53:46 by mhirch            #+#    #+#             */
/*   Updated: 2023/01/31 14:54:03 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>  
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(char *s);

#endif