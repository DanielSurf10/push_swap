/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:25:41 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/11 19:10:04 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux_lst;
	t_list	*new_lst;
	t_list	*aux_new_lst;

	aux_lst = lst;
	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (aux_lst)
	{
		aux_new_lst = ft_lstnew(f(aux_lst->content));
		if (!aux_new_lst)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, aux_new_lst);
		aux_lst = aux_lst->next;
	}
	return (new_lst);
}
