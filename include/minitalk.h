/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:40:07 by dodordev          #+#    #+#             */
/*   Updated: 2024/03/05 17:28:25 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// exit_codes
# define ERR_KILL_SGU2 "Could not send a signal;\n\
check server availability or pid validity!"
# define ERR_KILL_SGU1 "Could not send a signal;\n \
Client might've been killed!\n"
# define ERR_EXIT_SGU2 "Couldn't change SIGUSR2 behaviour\n"
# define ERR_EXIT_SGU1 "Couldn't change SIGUSR1 behaviour\n"

// helpers.c
int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int nb, int fd);
int		is_pid(char *spid);
void	exit_on_error(char *exit_code);

#endif