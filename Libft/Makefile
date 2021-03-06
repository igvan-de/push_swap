# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/17 12:10:38 by igvan-de       #+#    #+#                 #
#    Updated: 2019/10/08 13:38:28 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS =	ft_atoi.c \
		ft_atoilong.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_islower.c \
		ft_isupper.c \
		ft_isnum.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstaddend.c \
		ft_lstcount.c \
		ft_count_if.c \
		ft_itoalong.c \
		ft_arraylen.c \
		ft_swap.c \
		ft_strarrdel.c \
		get_next_line.c 
		
OBJ := $(SRCS:%.c=%.o)
INCLUDE = -I .././Includes
FLAGS = -Wall -Werror -Wextra $(INCLUDE)
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar rcs $(NAME) $(OBJ)

clean: 
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

author:
	@rm -f author
	@touch author
	@echo | env LOGNAME >>author
	@echo "Authorfile is made"

re: fclean all

print:
	@echo "$(OBJ)"

norm:
	@echo "===============NORMINETTE==============="
	@$(NORM) || echo "no norminette errors"
	@echo "========================================"