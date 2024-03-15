# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:54:27 by danbarbo          #+#    #+#              #
#    Updated: 2024/03/15 13:19:56 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
NAME_BONUS	:= checker
CFLAGS		:= -Wextra -Wall -Werror -g3

LIBFT_DIR	:= lib/libft
LIBFT		:= ${LIBFT_DIR}/libft.a
LIBS		:= ${LIBFT}

HEADERS		:= -I include \
				-I ${LIBFT_DIR}/include

SRCS		:= src/stack_moves/rev_rotate.c \
				src/stack_moves/swap.c \
				src/stack_moves/push.c \
				src/stack_moves/rotate.c \
				src/main.c \
				src/sorting_algorithm/position.c \
				src/sorting_algorithm/cost.c \
				src/sorting_algorithm/sort.c \
				src/sorting_algorithm/move.c \
				src/utils/utils_list.c \
				src/utils/make_stack.c \
				src/utils/utils.c \
				src/linked_list/ft_lstnew.c \
				src/linked_list/create_node.c \
				src/linked_list/lst_get_max_value.c \
				src/linked_list/ft_lstadd_back.c \
				src/linked_list/ft_lstdelone.c \
				src/linked_list/ft_lstadd_front.c \
				src/linked_list/lst_get_min_value.c \
				src/linked_list/lst_get_index.c \
				src/linked_list/ft_lstclear.c \
				src/linked_list/ft_lstlast.c \
				src/linked_list/ft_lstsize.c \
				src/linked_list/lst_get_node.c \
				src/linked_list/lst_contains.c
OBJS		:= ${SRCS:src/%.c=obj/%.o}

SRCS_BONUS	:= src_bonus/stack_moves/rev_rotate.c \
				src_bonus/stack_moves/swap.c \
				src_bonus/stack_moves/push.c \
				src_bonus/stack_moves/rotate.c \
				src_bonus/main.c \
				src_bonus/utils/utils_list.c \
				src_bonus/utils/get_next_line_utils.c \
				src_bonus/utils/make_stack.c \
				src_bonus/utils/utils.c \
				src_bonus/utils/get_next_line.c \
				src_bonus/execute_moves.c \
				src_bonus/linked_list/ft_lstnew.c \
				src_bonus/linked_list/create_node.c \
				src_bonus/linked_list/lst_get_max_value.c \
				src_bonus/linked_list/ft_lstadd_back.c \
				src_bonus/linked_list/ft_lstdelone.c \
				src_bonus/linked_list/ft_lstadd_front.c \
				src_bonus/linked_list/lst_get_min_value.c \
				src_bonus/linked_list/lst_get_index.c \
				src_bonus/linked_list/ft_lstclear.c \
				src_bonus/linked_list/ft_lstlast.c \
				src_bonus/linked_list/ft_lstsize.c \
				src_bonus/linked_list/lst_get_node.c \
				src_bonus/linked_list/lst_contains.c
OBJS_BONUS	:= ${SRCS_BONUS:src_bonus/%.c=obj_bonus/%.o}

all: ${NAME}
bonus: ${NAME_BONUS}

${NAME}: ${LIBFT} ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

${NAME_BONUS}: ${LIBFT} ${OBJS_BONUS}
	@${CC} ${OBJS_BONUS} ${LIBS} ${HEADERS} -o ${NAME_BONUS}

obj/%.o: src/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}
	@printf "Compiling: ${notdir $<}\n"

obj_bonus/%.o: src_bonus/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}
	@printf "Compiling: ${notdir $<}\n"

${LIBFT}:
	@make -C ${LIBFT_DIR} all

clean:
	@rm -rf obj
	@rm -rf obj_bonus
	@make -C ${LIBFT_DIR} clean

fclean: clean
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@make -C ${LIBFT_DIR} fclean

re: fclean all
re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus libft
