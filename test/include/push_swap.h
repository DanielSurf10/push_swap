/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:38:06 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 19:02:39 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>

#include <stdio.h>		// Apagar dps

#include "libft.h"

// struct

typedef struct s_list
{
	int				sorted_position;
	int				current_index;
	int				cost_a;
	int				cost_b;
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_push_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_push_swap;

// Main
t_list	*make_stack(int argc, char *argv[]);

// linked lists manipulation
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Utils list
t_list	*create_node(int num);
t_list	*lst_get_node(t_list *lst, int index);
t_list	*lst_get_min_value(t_list *lst);
t_list	*lst_get_first_below(t_list *lst, int max_value);
t_list	*lst_get_max_value(t_list *lst);
int		lst_get_index(t_list *lst, t_list *node);
int		lst_contains(t_list *lst, int num);
void	assign_sorted_positions(t_list *lst);
int		is_list_sorted(t_list *lst);
void	assign_current_indices(t_list *lst);
void	lst_assign_cost(t_list *lst_a, t_list *lst_b);
void	find_and_perform_cheapest_move(t_list **lst_a, t_list **lst_b);

// Utils
long	ft_atol(const char *str);
int		ft_abs(int num);

// Push
void	pa(t_list **lst_b, t_list **lst_a);
void	pb(t_list **lst_a, t_list **lst_b);

// Swap
void	sa(t_list **lst_a);
void	sb(t_list **lst_b);
void	ss(t_list **lst_a, t_list **lst_b);

// Rotate
void	ra(t_list **lst_a);
void	rb(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);

// Rev rotate
void	rra(t_list **lst_a);
void	rrb(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);


// Para apagar
void	print_stack(t_list *a, t_list *b);


#endif
