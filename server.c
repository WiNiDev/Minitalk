/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:45 by mberthoi          #+#    #+#             */
/*   Updated: 2022/03/16 15:36:37 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_arithmetic_conv(int sig)
{
	static int				current_bit;
	static unsigned char	message;

	if (sig == SIGUSR2)
		message = message | (1 << current_bit);
	current_bit++;
	if (current_bit == 8)
	{
		ft_putchar_fd(message, 1);
		current_bit = 0;
		message = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_arithmetic_conv);
	signal(SIGUSR2, ft_arithmetic_conv);
	while (1)
		pause();
	return (0);
}
