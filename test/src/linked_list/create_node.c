/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:46:56 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 19:47:23 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Creates a new node with the given number as content.
 *
 * @param num The number to be used as content for the new node.
 * @return The new node.
 */
t_list	*create_node(int num)
{
	int		*allocated;
	t_list	*list;

	allocated = (int *) malloc(sizeof(int));
	if (!allocated)
		return (NULL);
	*allocated = num;
	list = ft_lstnew(allocated);
	if (!list)
	{
		free(allocated);
		allocated = NULL;
		return (NULL);
	}
	return (list);
}
