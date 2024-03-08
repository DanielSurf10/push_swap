/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:25:12 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 12:49:01 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_is_int(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	num = atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	already_exists(t_list **lst, char *str_num)
{
	int	num;

	num = ft_atoi(str_num);

	if (lst_contains(*lst, num) == 1)
		return (1);
	ft_lstadd_front(lst, create_node(num));
	return (0);
}

int	has_only_int(int argc, char *argv[])
{
	int		iter_split;
	int		iter_argc;
	char	**split;
	t_list	*lst;

	iter_argc = 1;
	lst = NULL;
	while (iter_argc < argc)
	{
		iter_split = 0;
		split = ft_split(argv[iter_argc], ' ');
		while (split[iter_split])
		{
			if (string_is_int(split[iter_split]) == 0
				|| already_exists(&lst, split[iter_split]) == 1)
			{
				ft_free_split(split);
				ft_lstclear(&lst, free);
				return (0);
			}
			iter_split++;
		}
		ft_free_split(split);
		iter_argc++;
	}
	ft_lstclear(&lst, free);
	return (1);
}

int	validate(int argc, char *argv[])
{
	if (has_only_int(argc, argv) == 0)
		return (0);
	return (1);
}
