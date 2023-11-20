/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:52:44 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/06 20:08:03 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*x = *(unsigned char *) src; 
		x++;
		src++;
		n--;
	}
	return (dst);
}
