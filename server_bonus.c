/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:51:43 by psotto-m          #+#    #+#             */
/*   Updated: 2023/01/08 20:05:43 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int sinal, siginfo_t *info, void *ucontext)
{
	static int	c;
	static int	bit;	

	(void)ucontext;
	if (sinal == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	ft_printf("This is my PID: %d\n", getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &action, NULL) == -1)
			return (0);
		if (sigaction(SIGUSR2, &action, NULL) == -1)
			return (0);
		pause();
	}
}
