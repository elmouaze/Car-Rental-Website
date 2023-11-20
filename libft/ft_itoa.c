/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:08:15 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/12 04:18:45 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		wc;
	char	*res;
	int		i;

	i = 0;
	wc = ft_count(n);
	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	res = (char *) malloc(sizeof(char) * (wc + 1));
	if (!res)
		return (NULL);
	if (n < 0 && n != -2147483647)
	{
		n = n * -1;
		res[i++] = '-';
	}
	res[wc] = '\0';
	while (i < wc)
	{
		res[wc - 1] = (n % 10) + '0';
		n /= 10;
		wc--;
	}
	return (res);
}
