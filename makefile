# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/17 14:11:56 by igvan-de       #+#    #+#                 #
#    Updated: 2019/09/17 13:31:50 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

CHECKER = checker
PUSH_SWAP = push_swap
SRCS_CHECKER = checker.c operators.c operations_double.c stack.c
SRCS_PUSH_SWAP = push_swap.c operators.c operations_double.c stack.c delnode.c chunk.c algorithm.c push_back.c print.c
OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:%.c=%.o)
OBJ_CHECKER = $(SRCS_CHECKER:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
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
	@#removed make -C Libft because of "Nothing to to for make[1]" error 
	@#removed make -C Printf because of "Nothing to to for make[1]" error 
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
