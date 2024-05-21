/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:05:37 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/21 20:26:58 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minitalk.h"

static void ft_handler(int signal)
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
    ft_putstr_fd("Process ID : ", 1);
    write(1, "\n", 1);
    ft_putnbr_fd(getpid(),1);
    write(1, "\n", 1);
    signal(SIGUSR1, ft_handler);
    signal(SIGUSR2, ft_handler);
    while (1)
        pause();
    return (0);
}