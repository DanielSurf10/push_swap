/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:31 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/23 11:44:30 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	verify_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			exit_error();
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) != 1)
				exit_error();
			j++;
		}
		i++;
	}
}

static void	verify_int_size(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > MAX_INT || num < MIN_INT)
		exit_error();
}

static void	verify_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		verify_int_size(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				exit_error();
			j++;
		}
		i++;
	}
}

char	**validate_args(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (argc < 2)
		exit_error();
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_collect_mem_arr((void **)argv);
	}
	else
		argv = argv + 1;
	if (argv[0] == NULL)
		exit_error();
	verify_digits(argv);
	verify_duplicates(argv);
	return (argv);
}
