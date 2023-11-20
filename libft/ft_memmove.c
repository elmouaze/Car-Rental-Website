/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:19:47 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/06 21:34:57 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*s;

	tmp = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else 
	{
		while (len-- > 0)
		{
			tmp[len] = s[len];
		}
	}
	return (dst);
}
