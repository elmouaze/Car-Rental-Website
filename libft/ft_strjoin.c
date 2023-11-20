/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:47:52 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/08 08:55:37 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * size);
	index = 0;
	if (!res)
		return (NULL);
	while (*s1 && size > index)
	{
		res[index++] = *s1;
		s1++;
	}
	while (*s2 && size > index)
	{
		res[index++] = *s2;
		s2++;
	}
	res[index] = '\0';
	return (res);
}
