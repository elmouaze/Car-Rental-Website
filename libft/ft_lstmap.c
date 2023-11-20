/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:05:36 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/15 08:53:15 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	node = NULL;
	while (lst)
	{
		content = f(lst->content);
		p = ft_lstnew(content);
		if (!p)
		{
			free(content);
			ft_lstclear(&p, del);
			ft_lstclear(&node, del);
			return (0);
		}
		ft_lstadd_back(&node, p);
		lst = lst -> next;
	}
	return (node);
}
