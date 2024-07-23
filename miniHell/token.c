/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:29:24 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/23 08:45:30 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *new_token(char *str,token type)
{
	t_token *res;
	res = malloc(sizeof(t_token));
	res->str = str;
	res->type = type;
	res->next = NULL;
	return res;
}
t_token	*last_token(t_token *lst)
{
	t_token	*p;

	if (!lst)
		return (NULL);
	p = lst;
	while (p && p->next != NULL)
	{
		p = p->next;
	}
	return (p);
}
void	add_token(t_token **lst, t_token *new)
{
	t_token *node;

	if (!*lst)
		*lst = new;
	else
	{
		node = *lst;
		while (node && (node)->next != NULL)
		{
			node = (node)->next;
		}
		(node)->next = new;
	}
}