/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:47:48 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 22:41:41 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
