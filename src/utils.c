/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:26 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 10:58:20 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_index(t_list *lst, int index)
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

t_list	*lst_rev_index(t_list *lst, int index)
{
	int	len_list;

	len_list = ft_lstsize(lst);
	if (len_list <= index)
		return (NULL);
	return (lst_index(lst, len_list - index - 1));
}
