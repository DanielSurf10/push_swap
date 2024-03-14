/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:07:56 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 16:36:54 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Converts a string to a long integer.
 *
 * @param str The string to be converted.
 * @return The long integer.
 */
long	ft_atol(const char *str)
{
	int		i;
	int		signal;
	long	num;

	i = 0;
	signal = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * signal);
}

/**
 * @brief Gets the absolute value of a number.
 *
 * @param num The number to be converted.
 * @return The integer.
 */
int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
