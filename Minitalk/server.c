/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:43:20 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/08 17:43:24 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

static void	handler(int sig, siginfo_t *info, void *secret)
{
	(void) secret;
	if (sig == SIGUSR2)
	{
		g_msg.byte = g_msg.byte | (1 << g_msg.current_bit);
	}
	g_msg.current_bit++;
	if (g_msg.current_bit == 8)
	{
		ft_putchar_fd(g_msg.byte, 1);
		if (g_msg.byte == '\0')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_putstr_fd("Error when sending SIGUSR1 signal !\n", 2);
		}
		g_msg.byte = 0;
		g_msg.current_bit = 0;
	}
}

static void	print_pid(void)
{
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void) argv;
	if (argc != 1)
	{
		ft_putstr_fd("Usage : ./server \n", 1);
		return (0);
	}
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	print_pid();
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
