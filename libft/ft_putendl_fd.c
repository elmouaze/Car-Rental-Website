/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 06:24:36 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/16 12:19:27 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	index;

	if (fd < 0 || !s)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		write (fd, &s[index], 1);
		index++;
	}
	write (fd, "\n", 1);
}
