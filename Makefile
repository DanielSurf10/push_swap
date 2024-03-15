# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:54:27 by danbarbo          #+#    #+#              #
#    Updated: 2024/03/15 00:13:27 by danbarbo         ###   ########.fr        #
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

SRCS		:= src/utils_list.c \
				src/stack_moves/rev_rotate.c \
				src/stack_moves/swap.c \
				src/stack_moves/push.c \
				src/stack_moves/rotate.c \
				src/main.c \
				src/position.c \
				src/make_stack.c \
				src/cost.c \
				src/utils.c \
				src/sort.c \
				src/move.c \
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

SRCS_BONUS	:= ${wildcard src_bonus/*}				# Não esquecer de mudar isso auqi
OBJS_BONUS	:= ${SRCS_BONUS:src_bonus/%.c=obj/%.o}

all: ${NAME}
bonus: ${NAME_B}

${NAME}: ${LIBFT} ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

${NAME_B}: ${LIBFT} ${OBJS_BONUS}
	@${CC} ${OBJS_BONUS} ${LIBS} ${HEADERS} -o ${NAME_BONUS}

obj/%.o: src/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}
	@printf "Compiling: ${notdir $<}\n"

obj/%.o: src_bonus/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}
	@printf "Compiling: ${notdir $<}\n"

${LIBFT}:
	@make -C ${LIBFT_DIR} all

clean:
	@rm -rf obj
	@make -C ${LIBFT_DIR} clean

fclean: clean
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@make -C ${LIBFT_DIR} fclean

re: fclean all
re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus libft
