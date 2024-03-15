/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:27:54 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/08 20:24:27 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (0);
	last = get_last_node(*head);
	tmp = *head;
	*head = last;
	last->prev->next = NULL;
	(*head)->next = tmp;
	(*head)->prev = NULL;
	tmp->prev = (*head);
	return (1);
}

void	rra(t_stack **head, int to_print)
{
	if (reverse_rotate(head))
	{
		if (to_print == PRINT)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **head, int to_print)
{
	if (reverse_rotate(head))
	{
		if (to_print == PRINT)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **head_a, t_stack **head_b, int to_print)
{
	if (head_a == NULL || *head_a == NULL || (*head_a)->next == NULL)
		return ;
	if (head_b == NULL || *head_b == NULL || (*head_b)->next == NULL)
		return ;
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	if (to_print == PRINT)
		ft_printf("rrr\n");
}
