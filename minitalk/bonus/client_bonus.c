/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:31:16 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/26 11:45:59 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int ft_check_pid(char *id)
{
	int i;
	i = 0;
	while(i < (int)ft_strlen(id))
	{
		if(!ft_isdigit(id[i]))
			return(1);
		i++;
	}
	return 0;
}
int	handle_input(int ac, char *av)
{
	int pid;
	if (ac != 3 )
		return (ft_putstr_fd("Usage:<server-pid> <string>\n",1),-1);
	pid = ft_atoi(av);
	if(ft_check_pid(av) || pid < 2)
		return (ft_putstr_fd("Invalid pid",1),-1);
	else
		return (pid);
}

void sigusr_handler(int signum)
{
	static int count;

	count = 0;
	if (signum == SIGUSR2)
		count++;
		write(1, "Message received.\n", 18);
}
int main(int ac, char **av)
{
    int	i;
	char c;
    char *str;
    int pid;
	int count;

	i = 0;
	pid = handle_input(ac, av[1]);
	if (pid == -1)
		return 1;
	count = 0;
    str = av[2];
	signal(SIGUSR2, sigusr_handler);
	while (count <= ft_strlen(str))
	{
		c = str[count];
		while (i < 8)
		{  
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(1000);
		}
		count++;
		i = 0;
	}

    return (0);
}