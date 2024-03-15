# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:54:27 by danbarbo          #+#    #+#              #
#    Updated: 2024/03/14 21:27:22 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
NAME_BONUS	:= checker
CFLAGS		:= -Wextra -Wall -Werror -g3
# CFLAGS	:= -g3

LIBFT_DIR	:= lib/libft
LIBFT		:= ${LIBFT_DIR}/libft.a
LIBS		:= ${LIBFT}

HEADERS		:= -I include \
				-I ${LIBFT_DIR}/include

SRCS		:= ${shell find src -iname "*.c"}		# Não esquecer de mudar isso auqi
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
#	@make -C ${LIBFT_DIR} clean

fclean: clean
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
#	@make -C ${LIBFT_DIR} fclean

re: fclean all
re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus libft
