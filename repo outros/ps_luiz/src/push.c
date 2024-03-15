/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:07:15 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/05 11:31:01 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return (0);
	tmp = *dst;
	*dst = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	(*dst)->next = tmp;
	if (tmp)
		tmp->prev = (*dst);
	return (1);
}

void	pa(t_stack **head_a, t_stack **head_b, int to_print)
{
	if (push(head_a, head_b))
		if (to_print == PRINT)
			ft_printf("pa\n");
}

void	pb(t_stack **head_a, t_stack **head_b, int to_print)
{
	if (push(head_b, head_a))
		if (to_print == PRINT)
			ft_printf("pb\n");
}
