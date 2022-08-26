/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:01:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/08/26 02:45:17 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	char_to_bin(char c, int server_pid)
{
	int	i;

	i = 0;
	if (c < 0)
		return ;
	while (i < 8)
	{
		if (c % 2 == 1)
			kill(server_pid, SIGUSR1);
		else if (c % 2 == 0)
			kill(server_pid, SIGUSR2);
		c /= 2;
		usleep(300);
		i++;
	}
}

void	send(char *str, int server_pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bin(str[i], server_pid);
		i++;
	}
	char_to_bin(0, server_pid);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	pid_t	pid;

	pid = getpid();
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("ERROR: INVALID PID\n");
			return (EXIT_FAILURE);
		}
		send(argv[2], server_pid);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("\nWRONG NUMBER OF ARGUMENTS!\n");
		ft_printf("USAGE --> ./client [server_pid] \"text\"\n\n");
		return (EXIT_FAILURE);
	}
}
