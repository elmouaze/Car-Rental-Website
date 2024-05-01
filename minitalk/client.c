/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:29:46 by ael-moua          #+#    #+#             */
/*   Updated: 2024/04/21 09:31:31 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static int ft_check_pid(char *id)
{
	int i ;
	i = 0;
	while(i < ft_strlen(id))
	{
		if(ft_isalpha(id[i]))
			return(1);
		i++;
	}
	return 0;
}
int main(int ac, char **av)
{
    int	i;
	char c;
    char *str;
    int pid;

	i = 0;
    c = 0;
    str = av[2];
	pid = ft_atoi(av[1]);
	if (ac < 3 )
		return (ft_putstr_fd("Usage:<server-pid> <string>\n",1),NULL);
	if(ft_check_pid(av[1]) || pid < 2)
		return (ft_putstr_fd("Invalid pid",1),NULL);
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(500);
		}
		str++;
		i = 0;
	}
    return (0);
}