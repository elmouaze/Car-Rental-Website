/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:59:10 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/12 10:01:08 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;
	int		index;

	size = ft_strlen(s1);
	index = 0;
	res = (char *)malloc (sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (s1[index] != '\0')
	{
		res[index] = s1[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
