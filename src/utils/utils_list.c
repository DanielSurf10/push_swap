/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:26 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 23:55:16 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_get_first_below(t_list *lst, int max_pos)
{
	if (max_pos == 0)
		return (lst_get_min_value(lst));
	while (lst)
	{
		if (lst->sorted_position <= max_pos)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	is_list_sorted(t_list *lst)
{
	int		i;
	t_list	*aux;

	aux = lst;
	if (aux)
		i = lst->sorted_position;
	while (aux)
	{
		if (aux->sorted_position != i)
			return (0);
		aux = aux->next;
		i++;
	}
	return (1);
}
