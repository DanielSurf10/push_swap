/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:04:52 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 11:09:36 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rev_rotate(t_list **lst)
{
	int		lst_size;
	t_list	*last_node;
	t_list	*penultimate;

	lst_size = ft_lstsize(*lst);
	if (lst_size >= 2)
	{
		last_node = ft_lstlast(*lst);
		penultimate = lst_index(*lst, lst_size - 2);
		penultimate->next = NULL;
		last_node->next = *lst;
		*lst = last_node;
	}
}

void	rra(t_list **lst_a)
{
	lst_rev_rotate(lst_a);
}

void	rrb(t_list **lst_b)
{
	lst_rev_rotate(lst_b);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	lst_rev_rotate(lst_a);
	lst_rev_rotate(lst_b);
}
