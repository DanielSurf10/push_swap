/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:28 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 11:38:07 by danbarbo         ###   ########.fr       */
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
	lst_swap(*lst_a);
}

void	sb(t_list **lst_b)
{
	lst_swap(*lst_b);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	lst_swap(*lst_a);
	lst_swap(*lst_b);
}
