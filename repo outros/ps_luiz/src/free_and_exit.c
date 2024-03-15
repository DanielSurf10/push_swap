/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:25 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/19 11:39:38 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	ft_free_memory();
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_success(void)
{
	ft_free_memory();
	exit(EXIT_SUCCESS);
}
