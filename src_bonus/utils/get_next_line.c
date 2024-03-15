/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:27:51 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 11:04:00 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * @brief Adds the characters from `line_part` to the linked list `line`.
 *
 * @param line The address of the pointer to the linked list.
 * @param line_part The string containing the characters to be added.
 * @param size_readed The number of characters read from the input.
 * @return The status of the operation:
 *         - `FAIL` if `line_part` is NULL or if node creation fails.
 *         - `BUILD_STRING` if a newline character is encountered.
 *         - `READ` if `size_readed` is not zero and no newline character
 *            is found
 */
static int	put_in_list(t_list_gnl **line, char *line_part, int size_readed)
{
	int	i;
	int	status_node_creation;
	int	return_status;

	i = 0;
	return_status = READ;
	if (!line_part)
		return (FAIL);
	if (size_readed == 0)
		return (BUILD_STRING);
	while (i < size_readed)
	{
		status_node_creation = ft_gnl_lstadd_back(line, line_part[i]);
		if (status_node_creation == FAIL)
			return (FAIL);
		if (line_part[i] == '\n')
			return_status = BUILD_STRING;
		i++;
	}
	return (return_status);
}

/**
 * @brief Calculates the size of the next line in a linked list of type
 *        t_list_gnl.
 *
 * @param lst The linked list to calculate the size for.
 * @return The size of the next line in the linked list.
 */
static int	ft_lst_next_line_size(t_list_gnl *lst)
{
	int			i;
	t_list_gnl	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		i++;
		if (aux->content == '\n')
			return (i);
		aux = aux->next;
	}
	return (i);
}

/**
 * @brief Builds a line from a linked list of characters.
 *
 * This function takes a linked list of characters and constructs a line by
 * concatenating the characters in the list. It then frees the memory of the
 * linked list nodes.
 *
 * @param line A pointer to a pointer to the head of the linked list.
 * @return A pointer to the constructed line, or NULL if an error occurred.
 */
static char	*build_line(t_list_gnl **line)
{
	int			i;
	int			line_size;
	char		*line_to_return;
	t_list_gnl	*aux;

	i = 0;
	if (*line == NULL)
		return (NULL);
	line_size = ft_lst_next_line_size(*line);
	line_to_return = (char *) malloc(line_size + 1);
	if (!line_to_return)
		return (NULL);
	line_to_return[line_size] = '\0';
	while (i < line_size)
	{
		aux = *line;
		line_to_return[i] = (*line)->content;
		*line = (*line)->next;
		free(aux);
		i++;
	}
	aux = NULL;
	return (line_to_return);
}

/**
 * @brief Reads from a file descriptor and stores the result in a linked list.
 *
 * @param fd The file descriptor to read from.
 * @param line A pointer to the linked list where the read lines will be stored.
 * @return A pointer to the concatenated line read from the file descriptor, or
 *         NULL if an error occurs.
 */
static char	*read_fd(int fd, t_list_gnl **line)
{
	int		read_status;
	char	*line_part;
	char	*line_to_return;

	read_status = READ;
	line_part = NULL;
	line_to_return = NULL;
	if (!line)
		return (NULL);
	while (read_status == READ)
	{
		line_part = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!line_part)
			return (NULL);
		read_status = read(fd, line_part, BUFFER_SIZE);
		if (read_status != FAIL)
			read_status = put_in_list(line, line_part, read_status);
		free(line_part);
		line_part = NULL;
	}
	if (read_status == FAIL)
		return (NULL);
	if (read_status == BUILD_STRING)
		line_to_return = build_line(line);
	return (line_to_return);
}

char	*get_next_line(int fd)
{
	char				*line_to_return;
	static t_list_gnl	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_to_return = read_fd(fd, &line);
	if (!line_to_return)
		ft_gnl_lstclear(&line);
	return (line_to_return);
}
