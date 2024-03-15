/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:12:09 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/01 15:25:00 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **head)
{
	t_stack	*a;
	t_stack	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return (0);
	a = *head;
	tmp = a->next->next;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->next = a;
	a->next = tmp;
	a->prev = (*head);
	if (tmp != NULL)
		tmp->prev = a;
	return (1);
}

void	sa(t_stack **head, int to_print)
{
	if (swap(head))
		if (to_print == PRINT)
			ft_printf("sa\n");
}

void	sb(t_stack **head, int to_print)
{
	if (swap(head))
		if (to_print == PRINT)
			ft_printf("sb\n");
}

void	ss(t_stack **head_a, t_stack **head_b, int to_print)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	swap(head_a);
	swap(head_b);
	if (to_print == PRINT)
		ft_printf("ss\n");
}
