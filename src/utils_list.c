/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:26 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 20:23:18 by danbarbo         ###   ########.fr       */
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
	t_list	*node;

	node = NULL;
	if (until == 0)
		return (lst_min_value(lst));
	while (lst && lst->content == NULL)
		lst = lst->next;
	while (lst)
	{
		if (lst->content && *((int *)lst->content) < until)
		{
			node = lst;
			break ;
		}
		lst = lst->next;
	}
	return (node);
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
			return (i);
		i++;
		aux = aux->next;
	}
	return (-1);
}
