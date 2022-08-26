/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:25:05 by dcorenti          #+#    #+#             */
/*   Updated: 2022/08/26 02:48:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

static void	signal_action(int sig)
{
	usleep(300);
	ft_printf("ok\n\n");
	if (sig == SIGUSR2)
	{
		ft_printf("The server has confirmed that\n");
		ft_printf("the message was successfully received!\n");
		exit(0);
	}
}

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
		signal(SIGUSR1, signal_action);
		signal(SIGUSR2, signal_action);
		pause();
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
		ft_printf("Waiting response from the server...\n\n");
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
