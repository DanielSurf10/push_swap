/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:22:20 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 13:04:41 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	execute_swap(t_push_swap *push_swap, char *line)
{
	int	executed;

	executed = 0;
	if (ft_strncmp(line, "sa\n", -1) == 0)
	{
		sa(&push_swap->stack_a);
		executed = 1;
	}
	else if (ft_strncmp(line, "sb\n", -1) == 0)
	{
		sb(&push_swap->stack_b);
		executed = 1;
	}
	else if (ft_strncmp(line, "ss\n", -1) == 0)
	{
		ss(&push_swap->stack_a, &push_swap->stack_b);
		executed = 1;
	}
	return (executed);
}

static int	execute_rotate(t_push_swap *push_swap, char *line)
{
	int	executed;

	executed = 0;
	if (ft_strncmp(line, "ra\n", -1) == 0)
	{
		ra(&push_swap->stack_a);
		executed = 1;
	}
	else if (ft_strncmp(line, "rb\n", -1) == 0)
	{
		rb(&push_swap->stack_b);
		executed = 1;
	}
	else if (ft_strncmp(line, "rr\n", -1) == 0)
	{
		rr(&push_swap->stack_a, &push_swap->stack_b);
		executed = 1;
	}
	return (executed);
}

static int	execute_rev_rotate(t_push_swap *push_swap, char *line)
{
	int	executed;

	executed = 0;
	if (ft_strncmp(line, "rra\n", -1) == 0)
	{
		rra(&push_swap->stack_a);
		executed = 1;
	}
	else if (ft_strncmp(line, "rrb\n", -1) == 0)
	{
		rrb(&push_swap->stack_b);
		executed = 1;
	}
	else if (ft_strncmp(line, "rrr\n", -1) == 0)
	{
		rrr(&push_swap->stack_a, &push_swap->stack_b);
		executed = 1;
	}
	return (executed);
}

int	execute_sorting_instructions(t_push_swap *push_swap)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, "pa\n", -1) == 0)
			pa(&push_swap->stack_b, &push_swap->stack_a);
		else if (ft_strncmp(line, "pb\n", -1) == 0)
			pb(&push_swap->stack_a, &push_swap->stack_b);
		else if (execute_swap(push_swap, line) == 0
			&& execute_rotate(push_swap, line) == 0
			&& execute_rev_rotate(push_swap, line) == 0)
		{
			ft_putendl_fd("Error", 2);
			free(line);
			line = get_next_line(-1);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	get_next_line(-1);
	return (0);
}
