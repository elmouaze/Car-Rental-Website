/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:07:44 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/15 10:19:49 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char const	*s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		index;
	int		end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	index = 0;
	while (is_sep(s1[index], set) == 1 && s1[index] != '\0')
		index++;
	while (is_sep(s1[end - 1], set) == 1 && end >= index)
		end--;
	if (index >= end)
		return (ft_strdup(""));
	res = (char *)malloc (sizeof(char) * (end - index + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	ft_strlcpy(res, &s1[index], end - index + 1);
	return (res);
}
