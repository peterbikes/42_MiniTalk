/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:51:49 by psotto-m          #+#    #+#             */
/*   Updated: 2023/01/08 20:04:09 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_kill(char c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)) == 0)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(50);
		i++;
	}
}

void	send_msg(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received on server.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;
	int					i;

	sa.sa_handler = &send_msg;
	i = 0;
	if (argc != 3)
	{
		ft_printf("Whoops! Try Again!\n");
		ft_printf("Run me like this: \"./client <server PID> <message>. \"\n");
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_kill(argv[2][i], server_pid);
		i++;
	}
	send_kill(argv[2][i], server_pid);
	send_kill('\n', server_pid);
	return (0);
}
