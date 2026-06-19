/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:39:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 17:59:10 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [ ] - Não inicicado
// [-] - Iniciado
// [X] - Finalizado

//	[X] Colocar o sorted_position em cada nó na pilha A
//	[X]	Fazer push para a pilha b até sobrar 3 elementos
//	[X]	Ordenar com 3 elementos
//	[X]	while até a pilha b acabar
//	[X]		Colocar a posição atual de cada nó nas 2 pilhas - current_index
//	[X]		Na pilha B colocar o target em cada nó - absolute_target_pos
//				Colocar o target como o menor index da pilha A do que é maior que o nó respectivo da pilha B
//				Esse index na pilha A tem uma pos
//				E é isso que vai para o target no nó na pilha B
//	[X]		Calcular o cost
//				cost_a
//					É o target, só que ele pode ir pra cima (positivo) ou para baixo (negativo), em relação ao meio da pilha
//				cost_b
//					É a pos, só que ele pode ir pra cima (positivo) ou para baixo (negativo), em relação ao meio da pilha
//	[X]		Calcular o movimento com o menor custo
//				Ver qual é a menor soma entre cos_a e cos_b
//				Esse vai ser o movimento
//	Acabou o while
//	[X]	Rotate ou rev rotate até estar totalmente ordenado

//	[X]	Validar os argumentos `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` e números inteiros
//	[X]		Validar opcionais
//	[X]		Validar números
//
//	[X]	Fazer a função que calcula a disordem dos elementos
//	[X]	Fazer roteamento de qual algoritmo será usado, usando os argumentos ou não
//	[X]	Fazer algoritmo com complexidade O(n²)
//	[X]	Fazer algoritmo com complexidade O(n√n)
//	[X]	Fazer algoritmo com complexidade O(nlog(n))
//	[X]	Implementar lógica do `--bench`

int	main(int argc, char *argv[])
{
	int			status;
	float		disorder;
	t_options	options;
	t_push_swap	push_swap;

	if (argc < 2)
		return (0);

	push_swap = (t_push_swap){0};
	options = (t_options){0};
	status = parse_args(argc, argv, &options, &push_swap.stack_a);

	if (status == ERROR)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}

	if (!push_swap.stack_a)
		return (0);

	disorder = compute_disorder(push_swap.stack_a);
	if (disorder != 0 && push_swap.stack_a)
	{
		assign_sorted_positions(push_swap.stack_a);
		if (options.algorithm_selected == SIMPLE
			|| (options.algorithm_selected == ADAPTIVE && disorder <= 0.2))
			sort_simple_algorithm(&push_swap);
		else if (options.algorithm_selected == MEDIUM
			|| (options.algorithm_selected == ADAPTIVE && disorder <= 0.5))
			sort_medium_algorithm(&push_swap);
		else
			sort_complex_algorithm(&push_swap);

		ft_lstclear(&push_swap.stack_a, free);
	}

	ft_lstclear(&push_swap.stack_a, free);
	if (options.bench_mode)
		print_benchmark(push_swap.bench, options.algorithm_selected, disorder);

	return (0);
}
