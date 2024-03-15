/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:50:37 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 10:23:44 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	lst_get_index(t_list *lst, t_list *node)
{
	int		i;
	int		num;
	t_list	*aux;

	i = 0;
	num = *((int *) node->content);
	aux = lst;
	while (aux)
	{
		if (aux->content && *((int *)(aux->content)) == num)
			break ;
		aux = aux->next;
		i++;
	}
	return (i);
}
