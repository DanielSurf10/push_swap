/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:57 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 17:36:13 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rotate(t_list **lst)
{
	int		lst_size;
	t_list	*last_node;
	t_list	*first_node;

	lst_size = ft_lstsize(*lst);
	if (lst_size >= 2)
	{
		first_node = *lst;
		last_node = ft_lstlast(*lst);
		*lst = (*lst)->next;
		first_node->next = NULL;
		last_node->next = first_node;
	}
}

void	ra(t_list **lst_a)
{
	write(1, "ra\n", 3);
	lst_rotate(lst_a);
}

void	rb(t_list **lst_b)
{
	write(1, "rb\n", 3);
	lst_rotate(lst_b);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	write(1, "rr\n", 3);
	lst_rotate(lst_a);
	lst_rotate(lst_b);
}
