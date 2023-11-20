/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:47:45 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/06 02:03:36 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*r;

	r = (unsigned char *)ptr;
	while (n > 0)
	{
		*r = (unsigned char) x;
		n--;
		r++;
	}
	return (ptr);
}
