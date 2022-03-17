/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:25:51 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/04 04:27:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

static int	fill_octet(int sig)
{
	if (sig == SIGUSR1)
		return (1);
	return (0);
}

static char	convert_bin_to_char(int *signal_octet)
{
	int	i;
	int	c;

	i = 8;
	c = 0;
	while (i >= 0)
	{
		if (signal_octet[i] == 1)
			c += pow_tow(i);
		i--;
	}
	return ((char)c);
}

static int	print_string(int *j, char **str, int *realloc_size, int c_pid)
{
	if (str && (*str)[*j] == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = NULL;
		*j = -1;
		*realloc_size = STR_MAX_LEN;
		kill(c_pid, SIGUSR2);
	}
	*j += 1;
	return (0);
}

static void	decode(int sig, siginfo_t *info, void *context)
{
	static int	signal_octet[8];
	static int	i = 0;
	static int	j = 0;
	static char	*str = NULL;
	static int	realloc_size = STR_MAX_LEN;

	(void)context;
	if (!str)
		str = malloc(sizeof(char) * realloc_size);
	if (!str)
		return ;
	signal_octet[i++] = fill_octet(sig);
	if (i > 7)
	{
		if (j == (realloc_size - 1))
		{
			str[j] = 0;
			str = ft_realloc(str, STR_MAX_LEN);
			realloc_size += STR_MAX_LEN;
		}
		str[j] = convert_bin_to_char(signal_octet);
		i = print_string(&j, &str, &realloc_size, info->si_pid);
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("\t\t --HELLO, WELCOME IN MINITALK--\n\n");
	ft_printf("You can chat with me with this PID: %s\n", ft_itoa(pid));
	ft_printf("Let's go:\n\n");
	s_sigaction.sa_sigaction = decode;
	s_sigaction.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &s_sigaction, 0);
		sigaction(SIGUSR2, &s_sigaction, 0);
		pause();
	}
	return (EXIT_SUCCESS);
}
