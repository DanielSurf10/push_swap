/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:26 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 12:21:39 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*lst_min_value(t_list *lst)
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

t_list	*lst_max_value(t_list *lst)
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

t_list	*lst_min_group(t_list *lst, int until)
{
	if (until == 0)
		return (lst_min_value(lst));
	// if (until == 0)
	// 	return (lst);
	// while (lst && lst->content == NULL)
	// 	lst = lst->next;
	while (lst)
	{
		// if (lst->content && *((int *)lst->content) < until)
		// {
		// 	node = lst;
		// 	break ;
		// }
		if (lst->sorted_position <= until)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*lst_min_value_greater_than(t_list *lst, int num)
{
	t_list	*min;
	t_list	*aux;

	min = lst_max_value(lst);		// A variável chama min, pq vai retornar o menor valor
	if (!lst || !min || !min->content || num >= *((int *) min->content))
		return (NULL);
	aux = lst;
	while (aux)
	{
		if (aux->content && min->content)
			if (*((int *) aux->content) > num
				&& *((int *) aux->content) < *((int *) min->content))
				min = aux;
		aux = aux->next;
	}
	return (min);
}

int	lst_get_index(t_list *lst, int num)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		if (aux->content && *((int *)(aux->content)) == num)
			break ;
		i++;
		aux = aux->next;
	}
	return (i);
}

void	lst_assign_sorted_positions(t_list *lst)
{
	int		index;
	t_list	*min;

	index = 1;
	min = lst_min_value(lst);
	while (min)
	{
		min->sorted_position = index;
		min = lst_min_value_greater_than(lst, *((int *) min->content));
		index++;
	}
}

int	lst_is_sorted(t_list *lst)
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
		i++;
		aux = aux->next;
	}
	return (1);
}

void	lst_assign_indices(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		aux->current_index = i;
		aux = aux->next;
		i++;
	}
}

t_list	*lst_min_sorted_position_greater_than(t_list *lst, int num)
{
	t_list	*min;
	t_list	*aux;

	min = lst_max_value(lst);
	if (num >= min->sorted_position)
		return (lst_min_value(lst));
	aux = lst;
	while (aux)
	{
		if (aux->sorted_position > num && aux->sorted_position < min->sorted_position)
			min = aux;
		aux = aux->next;
	}
	return (min);
}

void	lst_assign_target(t_list *lst_a, t_list *lst_b)
{
	t_list	*aux;
	t_list	*min_greather_than;

	aux = lst_b;
	min_greather_than = lst_b;
	while (aux)
	{
		min_greather_than = lst_min_sorted_position_greater_than(lst_a, aux->sorted_position);
		aux->absolute_target_pos = min_greather_than->current_index;
		aux = aux->next;
	}

}
