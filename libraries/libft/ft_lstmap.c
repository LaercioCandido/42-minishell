/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:05:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/29 18:14:05 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*copy;

	new = 0;
	while (lst)
	{
		copy = ft_lstnew(f(lst->content));
		if (!(copy))
		{
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, copy);
		lst = lst->next;
	}
	return (new);
}
