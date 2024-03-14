/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_max_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:49:02 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 19:49:21 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gets the node with the maximum value in the list.
 *
 * @param lst The list to search in.
 * @return The node with the maximum value in the list.
 */
t_list	*lst_get_max_value(t_list *lst)
{
	t_list	*max;

	max = NULL;
	while (lst && lst->content == NULL)
		lst = lst->next;
	if (lst)
		max = lst;
	while (lst)
	{
		if (lst->content && *((int *)lst->content) > *((int *)max->content))
			max = lst;
		lst = lst->next;
	}
	return (max);
}
