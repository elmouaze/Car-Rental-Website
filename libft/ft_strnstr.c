/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:24:19 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/08 00:12:26 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	if (!needle || len == 0)
		return (NULL);
	while (*haystack != '\0' && len >= n)
	{
		if (ft_strncmp (haystack, needle, n) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
