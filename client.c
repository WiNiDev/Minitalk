/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:38 by mberthoi          #+#    #+#             */
/*   Updated: 2022/03/16 15:33:06 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	ft_send_signal(int pid, char *str)
{
	int	i;
	int	current_bit;

	i = 0;
	current_bit = 0;
	while (str[i])
	{
		while (current_bit < 8)
		{
			if (str[i] & (1 << current_bit))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			current_bit++;
			usleep(100);
		}
		current_bit = 0;
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client [server-pid] [message]\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	ft_send_signal(pid, av[2]);
	return (0);
}
