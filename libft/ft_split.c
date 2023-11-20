/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:27:43 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/11 05:27:01 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	index;
	int	size;

	size = 0;
	index = 0;
	while (str[index] != '\0')
	{
		while (str[index] == sep && str[index] != '\0')
			index++;
		if (str[index] != sep && str[index] != '\0')
			size++;
		while (str[index] != sep && str[index] != '\0')
			index++;
	}
	return (size);
}

static void	ft_free_memory(char **list, int max_index)
{
	while (max_index >= 0)
	{
		free(list[max_index]);
		max_index--;
	}
	free(list);
}

static void	ft_fill_word(char *res, char const *str, char c)
{
	int	index;

	index = 0;
	while (str[index] != c && str[index] != '\0')
	{
		*res = str[index];
		index++;
		res++;
	}
	*res = '\0';
}

static int	ft_fill_res(char const *s, char c, int wc, char **res)
{
	int		word;
	int		w;
	int		i;
	int		j;

	i = 0;
	w = 0;
	while (s[i] != '\0' && w < wc)
	{
		word = 0;
		j = i;
		while (s[i] == c && s[i++] != '\0')
			j++;
		while (s[i] != c && s[i++] != '\0')
			word++;
		res[w] = (char *) malloc (sizeof(char) * (word + 1));
		if (!res[w])
		{
			ft_free_memory(res, w);
			return (0);
		}
		ft_fill_word(res[w++], (s + j), c);
	}
	res[w] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**res;
	int		cond;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, c);
	res = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	cond = ft_fill_res(s, c, wc, res);
	if (cond == 0)
		return (NULL);
	return (res);
}
