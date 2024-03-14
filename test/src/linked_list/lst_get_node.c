/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:31:34 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 20:18:51 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Retrieves the node at the specified index in a linked list.
 *
 * @param lst The linked list.
 * @param index The index of the node to retrieve.
 * @return The node at the specified index.
 */
t_list	*lst_get_node(t_list *lst, int index)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	if (index < 0)
		return (NULL);
	while (aux && i < index)
	{
		aux = aux->next;
		i++;
	}
	return (aux);
}
