/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:51:49 by psotto-m          #+#    #+#             */
/*   Updated: 2023/01/08 20:06:50 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

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
		send_kill(argv[2][i], server_pid);
		i++;
	}
	send_kill('\n', server_pid);
	return (0);
}
