/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:28 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 20:20:20 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two nodes of a linked list.
 *
 * The first node becomes the second and the second node becomes the first.
 *
 * @param lst A pointer to a pointer to the linked list.
 */
void	lst_swap(t_list **lst)
{
	int		lst_size;
	t_list	*first;
	t_list	*second;

	lst_size = ft_lstsize(*lst);
	if (lst_size >= 2)
	{
		first = *lst;
		second = (*lst)->next;
		first->next = second->next;
		second->next = first;
		*lst = second;
	}
}

/**
 * @brief Performs the swap operation on the given list
 *        and prints "sa" to the screen.
 *
 * @param lst_a A pointer to the list to perform the swap operation on.
 */
void	sa(t_list **lst_a)
{
	write(1, "sa\n", 3);
	lst_swap(lst_a);
}

/**
 * @brief Performs the swap operation on the given list
 *        and prints "sb" to the screen.
 *
 * @param lst_b A pointer to the list to perform the swap operation on.
 */
void	sb(t_list **lst_b)
{
	write(1, "sb\n", 3);
	lst_swap(lst_b);
}

/**
 * Executes the ss command and prints "ss" to the screen.
 *
 * This function swaps the top elements of two stacks, lst_a and lst_b,
 * and then prints "ss" to indicate the operation performed.
 *
 * @param lst_a The first stack.
 * @param lst_b The second stack.
 */
// Performs both sa and sb and print ss
void	ss(t_list **lst_a, t_list **lst_b)
{
	write(1, "ss\n", 3);
	lst_swap(lst_a);
	lst_swap(lst_b);
}
