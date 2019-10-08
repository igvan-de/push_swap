# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/17 14:11:56 by igvan-de       #+#    #+#                 #
#    Updated: 2019/10/08 14:44:05 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

CHECKER = checker
PUSH_SWAP = push_swap
SRCS_CHECKER = ./srcs_checker/checker.c ./srcs_checker/print_checker.c \
				./srcs_checker/checker_input.c ./srcs_overarching/operators.c \
				./srcs_overarching/operations_double.c ./srcs_overarching/stack.c \
				./srcs_checker/extra_print.c
SRCS_PUSH_SWAP = ./srcs_push_swap/push_swap.c ./srcs_push_swap/delnode.c \
				 ./srcs_push_swap/chunk.c ./srcs_push_swap/algorithm.c \
				 ./srcs_push_swap/push_back.c ./srcs_push_swap/print_push_swap.c \
				  ./srcs_push_swap/check_conditions.c ./srcs_overarching/operators.c \
				  ./srcs_overarching/operations_double.c ./srcs_overarching/stack.c 
OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:%.c=%.o)
OBJ_CHECKER = $(SRCS_CHECKER:%.c=%.o)
INCLUDE = -I ./Includes
FLAGS = -Wall -Werror -Wextra $(INCLUDE)
LIB = Printf/libftprintf.a
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')

all: $(LIB) $(OBJ_PUSH_SWAP) $(OBJ_CHECKER) $(CHECKER) $(PUSH_SWAP)

$(LIB):
	@make -C Libft
	@make -C Printf

%.o: %.c
	@gcc $(FLAGS) -o $@ $< -c

$(CHECKER): $(OBJ_CHECKER)
	@gcc $(FLAGS) $(OBJ_CHECKER) $(LIB) -o checker
	@echo "$(PRINT_PLUS) Compiling completed"

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
	@gcc $(FLAGS) $(OBJ_PUSH_SWAP) $(LIB) -o push_swap
	@echo "$(PRINT_PLUS) Compiling completed"

clean:
	@rm -f $(OBJ_PUSH_SWAP) && rm -f $(OBJ_CHECKER)
	@make -C ./Libft clean && make -C ./Printf clean
	@echo "$(PRINT_PLUS) Cleaning objectives completed"

fclean: clean
	@rm -f $(CHECKER) && rm -f $(PUSH_SWAP)
	@make -C ./Libft fclean && make -C ./Printf fclean
	@echo "$(PRINT_PLUS) Cleaning all completed"

re: fclean all
	@echo "$(PRINT_PLUS) Recompiling completed"

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"
