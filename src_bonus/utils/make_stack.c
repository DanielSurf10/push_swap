/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:25:12 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 19:38:12 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * @brief Checks if a string represents a valid integer.
 *
 * @param str The string to be checked.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
static int	string_is_int(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (!str[1])
			return (0);
		i++;
	}
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

/**
 * @brief Create a new node with the given number
 *        if it is not already in the list.
 *
 * Checks if a number already exists in the list.
 * If the number does not exist, it adds it to the list.
 *
 * @param num The number to be stored in the node
 * @return t_list* A pointer to the created node
 */
static int	already_exists(t_list **lst, char *str_num)
{
	int	num;

	num = ft_atoi(str_num);
	if (lst_contains(*lst, num) == 1)
		return (1);
	ft_lstadd_back(lst, create_node(num));
	return (0);
}

static void	*free_all(t_list **lst, char **split)
{
	ft_free_split(split);
	ft_lstclear(lst, free);
	return (NULL);
}

t_list	*make_stack(int argc, char *argv[])
{
	int		iter_split;
	int		iter_argc;
	char	**split;
	t_list	*lst;

	iter_argc = 0;
	lst = NULL;
	while (++iter_argc < argc)
	{
		iter_split = 0;
		split = ft_split(argv[iter_argc], ' ');
		while (split[iter_split])
		{
			if (string_is_int(split[iter_split]) == 0
				|| already_exists(&lst, split[iter_split]) == 1)
				return (free_all(&lst, split));
			iter_split++;
		}
		if (!split[0])
			return (free_all(&lst, split));
		ft_free_split(split);
	}
	return (lst);
}
