/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:31:08 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/31 06:32:51 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

static void	ft_reset(t_char_node *c, int pid)
{
	c->i = 0;
	ft_memset (c->print, 0, 5);
	c->pid = pid;
	c->bytes = 1;
	c->byte_index = 0;
	c->tmp = 0;
}

static int	ft_bytes_count(char text)
{
	int	cpt;

	cpt = 0;
	if ((text & 0b10000000) == 0b10000000)
	{
		while ((text << cpt) & 0b10000000)
			cpt++;
		return (cpt);
	}
	return (1);
}

static void	ft_printuni(t_char_node *c, int pid)
{
	if (c->print[0] == '\0')
	{
		write(1, "\n", 1);
		kill(c->pid, SIGUSR2);
	}
	else
		write (1, &c->print, c->bytes);
	ft_reset (c, pid);
}

static void	ft_handler(int signal, siginfo_t *info, void *cont)
{
	static t_char_node	*c;

	(void)cont;
	if (!c)
	{
		c = malloc (sizeof (t_char_node));
		if (!c)
			return ;
		ft_reset (c, info->si_pid);
	}
	if (c->pid != info->si_pid)
		ft_reset (c, info->si_pid);
	if (signal == SIGUSR2)
		c->tmp = c->tmp << 1;
	else if (signal == SIGUSR1)
		c->tmp = (c->tmp << 1) | 1;
	c->i++;
	if (c->i % 8 == 0 && c->i > 0)
	{
		if (c->i == 8)
			c->bytes = ft_bytes_count (c->tmp);
		(1) && (c->print[c->byte_index++] = c->tmp), (c->tmp = 0);
	}
	if (c->bytes * 8 == c->i)
		ft_printuni(c, info->si_pid);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &ft_handler;
	action.sa_flags = SA_SIGINFO;
	ft_putstr_fd ("Process ID: \n", 1);
	ft_putnbr_fd (getpid(), 1);
	write (1, "\n", 1);
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
