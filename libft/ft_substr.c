/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:38:46 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/08 08:23:43 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	int				index;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = (unsigned int) ft_strlen(s);
	index = 0;
	if (len > size - start)
		len = size - start;
	if (start > size)
		len = 0;
	p = (char *) malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if (size >= start)
	{
		while (s[start] != '\0' && len)
		{
			p[index++] = s[start++];
			len--;
		}
	}
	p[index] = '\0';
	return (p);
}
