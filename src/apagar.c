/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apagar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:36:13 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 12:12:18 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *a, t_list *b)
{
	t_list	*aux;
	(void)a;
	aux = a;
	fprintf(stderr, "\n\n");
	fprintf(stderr, "stack a:\n");
	fprintf(stderr, "| value | sorted index | current index | target pos | cost_a | cost_b | next           |\n");
	fprintf(stderr, "----------------------------------------------------------------------------------------\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %13d | %10d | %6d | %6d | %14p |\n", *((int *)aux->content), aux->sorted_position, aux->current_index, aux->absolute_target_pos, aux->cost_a, aux->cost_b, aux->next);
		aux = aux->next;
	}
	aux = b;
	fprintf(stderr, "\nstack b:\n");
	fprintf(stderr, "| value | sorted index | current index | target pos | cost_a | cost_b | next           |\n");
	fprintf(stderr, "----------------------------------------------------------------------------------------\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %13d | %10d | %6d | %6d | %14p |\n", *((int *)aux->content), aux->sorted_position, aux->current_index, aux->absolute_target_pos, aux->cost_a, aux->cost_b, aux->next);
		aux = aux->next;
	}
}
