/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:26:18 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/07 08:20:35 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	size;
	int		i;

	index = 0;
	i = 0;
	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	if (dstsize <= ft_strlen(dst))
		return (size + dstsize);
	while (dst[index] != '\0')
		index++;
	size += index; 
	while (index + 1 < dstsize && src[i] != '\0')
		dst[index++] = src[i++];
	dst[index] = '\0';
	return (size);
}
