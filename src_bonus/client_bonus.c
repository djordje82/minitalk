/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:09:31 by dodordev          #+#    #+#             */
/*   Updated: 2024/04/12 16:29:46 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_control = 0;

static void	wait_for_answer(void)
{
	int	i;

	i = 0;
	while (g_control == 0)
	{
		if (i == 50)
			exit_on_error(TMOU);
		usleep(100);
		++i;
	}
	g_control = 0;
}

static void	send_char_to_server(unsigned char c, __pid_t server_pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit_on_error(ERR_KILL_SGU1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit_on_error(ERR_EXIT_SGU2);
		}
		wait_for_answer();
		bit >>= 1;
	}
}

static void	sig_handler(int signum)
{
	g_control = 1;
	if (signum == 12)
		write(1, "confirmation received!\n", 23);
}

static int	str_to_c(__pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char_to_server(str[i], pid);
		++i;
	}
	send_char_to_server(0, pid);
	return (1);
}

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3 || !is_pid(argv[1]) || !argv[2])
		return (0);
	pid = (__pid_t)ft_atoi(argv[1]);
	signal(10, &sig_handler);
	signal(12, &sig_handler);
	if (!str_to_c(pid, argv[2]))
		return (0);
}
