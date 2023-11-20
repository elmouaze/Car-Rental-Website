/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:12:06 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/12 00:08:29 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_overflow(int s)
{
	if (s > 0)
		return (-1);
	return (0);
}

static int	ft_pass(const char *str)
{
	int	sign;
	int	index;

	sign = 1;
	index = 0;
	while (str[index] >= 9 && str[index] <= 13 || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] == '0' && str[index] != 0)
		index++;
	return (index * sign);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	int					count;
	int					index;

	res = 0;
	count = 0;
	sign = ft_pass(str);
	if (sign < 0)
		index = sign * (-1);
	else 
		index = sign;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - '0');
		index++;
		count++;
		if (count >= 20)
			return (ft_overflow(sign));
	}
	if (sign < 0)
		return ((int)res * (-1));
	return ((int)res);
}
