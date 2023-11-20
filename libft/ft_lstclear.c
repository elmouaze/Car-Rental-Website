/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:34:23 by ael-moua          #+#    #+#             */
/*   Updated: 2023/11/14 22:51:02 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*ptr2;

	if (!lst || !del)
		return ;
	ptr = *lst;
	ptr2 = *lst;
	while (ptr)
	{
		ptr2 = ptr2->next;
		del(ptr -> content);
		free(ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}
