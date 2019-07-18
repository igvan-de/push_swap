# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/17 14:11:56 by igvan-de       #+#    #+#                 #
#    Updated: 2019/07/18 17:32:43 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

CHECKER = checker
PUSH_SWAP = push_swap
SRCS_CHECKER = checker.c
SRCS_PUSH_SWAP = checker.c
OBJ = $(SRCS:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
LIB = Printf/libftprintf.a
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER):
	@make -C Libft
	@make -C Printf
	@gcc $(FLAGS) $(SRCS_CHECKER) $(LIB) -o checker
	@echo "$(PRINT_PLUS) Compiling completed"

$(PUSH_SWAP):
	#removed make -C Libft because of "Nothing to to for make[1]" error 
	#removed make -C Printf because of "Nothing to to for make[1]" error 
	@gcc $(FLAGS) $(SRCS_PUSH_SWAP) $(LIB) -o push_swap
	@echo "$(PRINT_PLUS) Compiling completed"

clean:
	@rm -f $(OBJ)
	@make -C ./Libft clean && make -C ./Printf clean
	@echo "$(PRINT_PLUS) Cleaning objectives completed"

fclean:
	@rm -f $(CHECKER) && rm -f $(PUSH_SWAP)
	@make -C ./Libft fclean && make -C ./Printf fclean
	@echo "$(PRINT_PLUS) Cleaning all completed"

re: fclean all
	@echo "$(PRINT_PLUS) Recompiling completed"

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"