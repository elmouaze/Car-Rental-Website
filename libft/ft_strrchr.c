/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:01:27 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/06 20:21:39 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*s1;

	s1 = (char *)s;
	size = ft_strlen(s);
	if (s1[size] == (char) c)
		return (&s1[size]);
	while (size != 0)
	{
		if (s1[size - 1] == (char) c)
			return (&s1[size - 1]);
		size--;
	}
	return (NULL);
}
