/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:29:46 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/31 02:50:18 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	ft_check_pid(char *id)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(id))
	{
		if (!ft_isdigit (id[i]))
			return (1);
		i++;
	}
	return (0);
}

int	handle_input(int ac, char *av)
{
	int	pid;

	if (ac != 3)
		return (ft_putstr_fd ("Usage:<server-pid> <string>\n", 1), -1);
	pid = ft_atoi(av);
	if (ft_check_pid (av) || pid < 2)
		return (ft_putstr_fd ("Invalid pid", 1), -1);
	else
		return (pid);
}

int	main(int ac, char **av)
{
	int		i;
	char	c;
	char	*str;
	int		pid;

	c = 0;
	pid = handle_input(ac, av[1]);
	if (pid == -1)
		return (1);
	str = av[2];
	while (*str)
	{
		i = 0;
		c = *(str++);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(500);
		}
	}
	return (0);
}
