/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:31:08 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/21 19:58:49 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk_bonus.h"

static void ft_handler(int signal, siginfo_t *info)
{
    static unsigned char c;
    static int i;

    if (signal == SIGUSR2)
        c = c << 1; 
    else if(signal == SIGUSR1)
        c = (c << 1) | 1;  
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}


int main(void)
{
    struct sigaction action;
    
	action.sa_sigaction = &ft_handler;
	action.sa_flags = SA_SIGINFO;
    
    ft_putstr_fd("Process ID : ", 1);
    write(1, "\n", 1);
    ft_putnbr_fd(getpid(),1);
    write(1, "\n", 1);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (1)
        pause();
    return (0);
}