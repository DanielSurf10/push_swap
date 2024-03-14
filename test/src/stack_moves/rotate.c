/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:57 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 20:21:14 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the list once, moving the first node to the last position.
 *
 * @param lst A pointer to the pointer of the list.
 */
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

/**
 * @brief Executes the 'ra' movement and prints it on the screen.
 *
 * @param lst_a A pointer to the list representing stack A.
 */
void	ra(t_list **lst_a)
{
	write(1, "ra\n", 3);
	lst_rotate(lst_a);
}

/**
 * @brief Executes the 'rb' movement and prints it on the screen.
 *
 * @param lst_b A pointer to the list representing stack B.
 */
void	rb(t_list **lst_b)
{
	write(1, "rb\n", 3);
	lst_rotate(lst_b);
}

/**
 * @brief Executes both commands ra and rb and displays "rr" on the screen.
 *
 * @param lst_a Pointer to the first stack.
 * @param lst_b Pointer to the second stack.
 */
void	rr(t_list **lst_a, t_list **lst_b)
{
	write(1, "rr\n", 3);
	lst_rotate(lst_a);
	lst_rotate(lst_b);
}
