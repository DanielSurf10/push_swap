/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_min_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:48:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 22:42:42 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_get_min_value(t_list *lst)
{
	t_list	*min;

	min = NULL;
	while (lst && lst->content == NULL)
		lst = lst->next;
	if (lst)
		min = lst;
	while (lst)
	{
		if (lst->content && *((int *)lst->content) < *((int *)min->content))
			min = lst;
		lst = lst->next;
	}
	return (min);
}
