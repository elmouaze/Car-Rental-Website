/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:41:32 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/16 12:20:00 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((int)count < 0 || (int)size < 0)
		return (NULL);
	p = (void *)malloc(size * count);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
