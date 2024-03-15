/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:45:04 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/01 15:19:50 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *head;
	last = get_last_node(*head);
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	ra(t_stack **head_a, int to_print)
{
	if (head_a == NULL || *head_a == NULL || (*head_a)->next == NULL)
		return ;
	rotate(head_a);
	if (to_print == PRINT)
		ft_printf("ra\n");
}

void	rb(t_stack **head_b, int to_print)
{
	if (head_b == NULL || *head_b == NULL || (*head_b)->next == NULL)
		return ;
	rotate(head_b);
	if (to_print == PRINT)
		ft_printf("rb\n");
}

void	rr(t_stack **head_a, t_stack **head_b, int to_print)
{
	if (head_a == NULL || *head_a == NULL || (*head_a)->next == NULL)
		return ;
	if (head_b == NULL || *head_b == NULL || (*head_b)->next == NULL)
		return ;
	rotate(head_a);
	rotate(head_b);
	if (to_print == PRINT)
		ft_printf("rr\n");
}
