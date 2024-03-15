/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:38:06 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 10:04:25 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

//****************************************************************************//
//                                  Structs                                   //
//****************************************************************************//

/**
 * @struct struct s_list
 * @brief Structure representing a linked list node.
 *
 * The `t_list` structure represents a node in a linked list.
 *
 * `cost_a` is the number of movements that stack A needs to make for the node
 *	 to be sorted.
 * `cost_b` is the number of movements that stack B needs to make for the node
 *	 to reach the top.
 * `current_index` is the current index for each time `cost_a` and `cost_b` are
 *	 calculated.
 * `sorted_position` is the position that the node should be if sorted.
 * `next` is a pointer to the next node in the list.
 */
typedef struct s_list
{
	int				cost_a;
	int				cost_b;
	int				current_index;
	int				sorted_position;
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @struct s_push_swap
 * @brief Represents the main structure for the push_swap program.
 *
 * This structure contains two linked lists, stack_a and stack_b, which
 * represent the two stacks used in the push_swap algorithm.
 */
typedef struct s_push_swap
{
	int		index;
	int		key_nbr;
	int		key_nbr_factor;
	int		lst_size;
	int		moves_to_sort;
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_push_swap;

//****************************************************************************//
//                               Main functions                               //
//****************************************************************************//

/**
 * @brief Create a stack object with the given arguments
 *
 * This function creates a stack object based on the provided command-line
 * arguments. The stack is represented as a linked list using the t_list
 * structure.
 *
 * @param argc The number of arguments
 * @param argv The arguments
 * @return t_list* A pointer to the created stack object
 */
t_list	*make_stack(int argc, char *argv[]);

//****************************************************************************//
//                             Sorting functions                              //
//****************************************************************************//

/**
 * @brief Sorts a list of 3 elements in ascending order.
 *
 * @param push_swap The push_swap struct containing the list to be sorted.
 */
void	sort_3_elements(t_push_swap *push_swap);

/**
 * @brief Rotate the stack until it is sorted.
 *
 * @param push_swap The push_swap struct containing the stack and other
 *                  variables.
 */
void	rotate_until_sorted(t_push_swap *push_swap);

/**
 * @brief Sorts the elements in the push_swap structure using a
 *        custom algorithm.
 *
 * @param push_swap A pointer to the push_swap structure.
 */
void	sort(t_push_swap *push_swap);

/**
 * @brief Pushes nodes from stack A to stack B until the size of stack A is
 *        greater than 3.
 *
 * @param push_swap The push_swap struct containing the stacks and other
 *                  variables.
 */
void	pust_nodes_to_b(t_push_swap *push_swap);

//****************************************************************************//
//                         Linked lists manipulation                          //
//****************************************************************************//

int		ft_lstsize(t_list *lst);

/**
 * @brief Checks if a list contains a given number.
 *
 * @param lst The list to check.
 * @param num The number to check for.
 * @return 1 if the list contains the number, 0 otherwise.
 */
int		lst_contains(t_list *lst, int num);

/**
 * @brief Gets the index of a node in a list.
 *
 * @param lst The list to search in.
 * @param node The node to get the index of.
 * @return The index of the node in the list.
 */
int		lst_get_index(t_list *lst, t_list *node);

/**
 * @brief Adds the element 'new' at the beginning of the linked list 'lst'.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param new The node to be added at the beginning of the list.
 */

void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Adds the element 'new' at the end of the linked list 'lst'.
 *
 * @param lst The address of a pointer to the first element of a linked list.
 * @param new The element to add at the end of the linked list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes a single node from a linked list.
 *
 * @param lst The node to be deleted.
 * @param del The function used to delete the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Clears a linked list and frees the memory of each node using the
 *        provided function.
 *
 * This function clears a linked list by iterating through each node and
 * applying the provided function `del` to free the memory allocated for
 * the content of each node. After clearing the list, the pointer to the
 * list (`lst`) will be set to NULL.
 *
 * @param lst A pointer to a pointer to the first node of the linked list.
 * @param del The function used to delete the content of each node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Creates a new node with the given number as content.
 *
 * @param num The number to be used as content for the new node.
 * @return The new node.
 */
t_list	*create_node(int num);

/**
 * @brief Creates a new linked list node with the specified content.
 *
 * @param content The content to be stored in the new node.
 * @return A pointer to the newly created node.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Returns the last element of a linked list.
 *
 * @param lst The head of the linked list.
 * @return The last element of the linked list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Gets the node with the minimum value in the list.
 *
 * @param lst The list to search in.
 * @return The node with the minimum value in the list.
 */
t_list	*lst_get_min_value(t_list *lst);

/**
 * @brief Gets the node with the maximum value in the list.
 *
 * @param lst The list to search in.
 * @return The node with the maximum value in the list.
 */
t_list	*lst_get_max_value(t_list *lst);

/**
 * @brief Retrieves the node at the specified index in a linked list.
 *
 * @param lst The linked list.
 * @param index The index of the node to retrieve.
 * @return The node at the specified index.
 */
t_list	*lst_get_node(t_list *lst, int index);

//****************************************************************************//
//                                 Utils list                                 //
//****************************************************************************//

/**
 * @brief Checks if a list is sorted.
 *
 * @param lst The list to check.
 * @return 1 if the list is sorted, 0 otherwise.
 */
int		is_list_sorted(t_list *lst);

/**
 * @brief Assigns the sorted position to each node in the list.
 *
 * The function assigns to each node the position it would have
 * if the list were sorted.
 *
 * @param lst The list to assign sorted positions to.
 */
void	assign_sorted_positions(t_list *lst);

/**
 * @brief Assigns the current index to each node in the list.
 *
 * @param lst The list to assign current indices to.
 */
void	assign_current_indices(t_list *lst);

/**
 * @brief Gets the first value that is smaller than the given position.
 *
 * @param lst The list to search in.
 * @return The node found or min value if max_pos is 0.
 */
t_list	*lst_get_first_below(t_list *lst, int max_value);

/**
 * @brief Gets the node with the minimum sorted position that is greater than
 *        the sorted position of a given node.
 *
 * @param lst The list to search in.
 * @param node The node to compare the sorted position with.
 * @return The node with the minimum sorted position that is greater than the
 *         sorted position of the given node.
 */
t_list	*get_min_sorted_position_greater_than(t_list *lst, t_list *node);

/**
 * @brief Assigns the cost to each node in the list.
 *
 * @param lst_a The list that will receive the values.
 * @param lst_b The list that will provide the values.
 */
void	lst_assign_cost(t_list *lst_a, t_list *lst_b);

/**
 * @brief Finds and performs the cheapest move to sort the list.
 *
 * @param lst_a The list that will receive the values.
 * @param lst_b The list that will provide the values.
 */
void	find_and_perform_cheapest_move(t_list **lst_a, t_list **lst_b);

//****************************************************************************//
//                                   Utils                                    //
//****************************************************************************//

/**
 * @brief Gets the absolute value of a number.
 *
 * @param num The number to be converted.
 * @return The integer.
 */
int		ft_abs(int num);

/**
 * @brief Converts a string to a long integer.
 *
 * @param str The string to be converted.
 * @return The long integer.
 */
long	ft_atol(const char *str);

//****************************************************************************//
//                             Movement functions                             //
//****************************************************************************//

//****************************************************************************//
//                                    Push                                    //
//****************************************************************************//

/**
 * @brief Perform and print pa.
 *
 * This function performs the pa operation, which moves the top element from
 * the stack B to the stack A. It also prints the operation "pa" to the
 * standard output.
 *
 * @param lst_b Pointer to the top of the stack B.
 * @param lst_a Pointer to the top of the stack A.
 */
void	pa(t_list **lst_b, t_list **lst_a);

/**
 * @brief Perform and print pb.
 *
 * This function performs the pb operation, which moves the top element from
 * the stack A to the stack B. It also prints the operation "pb" to the
 * standard output.
 *
 * @param lst_a Pointer to the top of the stack A.
 * @param lst_b Pointer to the top of the stack B.
 */
void	pb(t_list **lst_a, t_list **lst_b);

//****************************************************************************//
//                                    Swap                                    //
//****************************************************************************//

/**
 * @brief Performs the swap operation on the given list
 *        and prints "sa" to the screen.
 *
 * @param lst_a A pointer to the list to perform the swap operation on.
 */
void	sa(t_list **lst_a);

/**
 * @brief Performs the swap operation on the given list
 *        and prints "sb" to the screen.
 *
 * @param lst_b A pointer to the list to perform the swap operation on.
 */
void	sb(t_list **lst_b);

/**
 * Executes the ss command and prints "ss" to the screen.
 *
 * This function swaps the top elements of two stacks, lst_a and lst_b,
 * and then prints "ss" to indicate the operation performed.
 *
 * @param lst_a The first stack.
 * @param lst_b The second stack.
 */
void	ss(t_list **lst_a, t_list **lst_b);

//****************************************************************************//
//                                   Rotate                                   //
//****************************************************************************//

/**
 * @brief Executes the 'ra' movement and prints it on the screen.
 *
 * @param lst_a A pointer to the list representing stack A.
 */
void	ra(t_list **lst_a);

/**
 * @brief Executes the 'rb' movement and prints it on the screen.
 *
 * @param lst_b A pointer to the list representing stack B.
 */
void	rb(t_list **lst_b);

/**
 * @brief Executes both commands ra and rb and displays "rr" on the screen.
 *
 * @param lst_a Pointer to the first stack.
 * @param lst_b Pointer to the second stack.
 */
void	rr(t_list **lst_a, t_list **lst_b);

//****************************************************************************//
//                               Reverse Rotate                               //
//****************************************************************************//

/**
 * @brief Executes the reverse rotate operation on a given list and prints
 *        "rra" to the screen.
 *
 * @param lst_a A pointer to the list to perform the reverse rotate
 *              operation on.
 */
void	rra(t_list **lst_a);

/**
 * @brief Executes the reverse rotate operation on a given list and prints
 *        "rrb" to the screen.
 *
 * @param lst_b A pointer to the list to perform the reverse rotate
 *              operation on.
 */
void	rrb(t_list **lst_b);

/**
 * @brief Executes both rra and rrb operations
 *        and displays "rrr" on the screen.
 *
 * @param lst_a Pointer to the first stack.
 * @param lst_b Pointer to the second stack.
 */
void	rrr(t_list **lst_a, t_list **lst_b);

#endif
