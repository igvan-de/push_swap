/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 15:15:31 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/06 17:40:20 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/includes/libft.h"
#include "./Libft/includes/get_next_line.h" //Not sure if this is needed. CHECK LATER!!!
#include "./Printf/ft_printf.h"

#include <stdlib.h>


typedef struct 			s_stack
{
	int					number;
	struct s_stack		*next;
}             			t_stack;


int					sa(char **argv);

void				ft_stackadd(t_stack **alst, t_stack *new);

t_stack 			*ft_newnode(int number);