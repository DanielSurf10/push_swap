/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:47:48 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 19:47:57 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if a list contains a given number.
 *
 * @param lst The list to check.
 * @param num The number to check for.
 * @return 1 if the list contains the number, 0 otherwise.
 */
int	lst_contains(t_list *lst, int num)
{
	while (lst)
	{
		if (lst->content && *((int *) lst->content) == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}
