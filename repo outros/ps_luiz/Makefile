NAME 			= push_swap
NAME_BONUS		= checker
CFLAGS			= -Werror -Wall -Wextra -g3
CC 				= cc $(CFLAGS)

LIBFT			= lib/libft/libft.a
LIBFT_PATH		= lib/libft/

HEADER			= -I lib/libft/src -I src/

SRC_FILES		= main.c \
				  free_and_exit.c \
				  index.c \
				  stack.c \
				  swap.c \
				  push.c \
				  rotate.c \
				  reverse_rotate.c \
				  sort.c \
				  position.c \
				  cost.c \
				  move.c \
				  validate_args.c

SRC_FILES_BONUS = $(filter-out main.c, $(SRC_FILES))

OBJ_FILES		= $(SRC_FILES:%.c=%.o)
OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:%.c=%.o)

SRC_FOLDER 		= src/
OBJ_FOLDER		= obj/

SRC 			= $(addprefix $(SRC_FOLDER), $(SRC_FILES))
OBJ				= $(addprefix $(OBJ_FOLDER), $(OBJ_FILES)) 
OBJ_BONUS 		= $(addprefix $(OBJ_FOLDER), $(OBJ_FILES_BONUS))

SRC_BONUS_MAIN = src_bonus/main_bonus.c
OBJ_BONUS_MAIN = src_bonus/main_bonus.o

all: libft $(NAME)

libft:
	@make -C $(LIBFT_PATH) --silent

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(HEADER) -o $(NAME)

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c
	@mkdir -p $(OBJ_FOLDER)
	$(CC) $< -o $@ -c $(HEADER)

# bonus
bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS_MAIN)
	$(CC) $(OBJ_BONUS_MAIN) $(OBJ_BONUS) $(LIBFT) $(HEADER) -o $(NAME_BONUS)

$(OBJ_BONUS_MAIN): $(SRC_BONUS_MAIN)
	$(CC) $< -o $@ -c $(HEADER)



# utils 
clean:
	@rm -rf obj
	@rm -rf src_bonus/main_bonus.o
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf push_swap
	@rm -rf checker
	@make -C $(LIBFT_PATH) fclean

re: fclean all

test: all
	clear && ./push_swap 5 4 3 2 1 0 89 49 -2 -323 -43 84 -10

.PHONY: all clean fclean re

# normal test
test2: all
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: all    
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test10: all    
	$(eval ARG = $(shell shuf -i 0-100 -n 10))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: all
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: all    
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

#my test
mytest2: all bonus
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

mytest3: all bonus    
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

mytest10: all bonus    
	$(eval ARG = $(shell shuf -i 0-100 -n 10))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

mytest100: all bonus
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

mytest500: all bonus    
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

#val test
val1: all
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./push_swap $(ARG)

val2: all
	$(eval ARG = $(shell shuf -i 0-5000 -n 2))
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./push_swap $(ARG)

val3: all
	$(eval ARG = $(shell shuf -i 0-5000 -n 3))
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./push_swap $(ARG)

val4: all
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./push_swap "" 2

val5: all
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./push_swap "5 32 532546 1 -4234 213123123"

val6: all
	$(eval ARG = $(shell shuf -i 0-5000 -n 3))
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./checker $(ARG)

val7: all bonus
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./push_swap $(ARG) | ./checker $(ARG)

val8: all bonus
	valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes ./checker "-01 -001"