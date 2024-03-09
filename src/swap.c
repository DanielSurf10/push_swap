/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:28 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 17:36:33 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_swap(t_list *lst)
{
	int	lst_size;
	int	*num;

	lst_size = ft_lstsize(lst);
	if (lst_size >= 2)
	{
		num = lst->content;
		lst->content = lst->next->content;
		lst->next->content = num;
	}
}

void	sa(t_list **lst_a)
{
	write(1, "sa\n", 3);
	lst_swap(*lst_a);
}

void	sb(t_list **lst_b)
{
	write(1, "sb\n", 3);
	lst_swap(*lst_b);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	write(1, "ss\n", 3);
	lst_swap(*lst_a);
	lst_swap(*lst_b);
}
