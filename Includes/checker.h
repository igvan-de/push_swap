/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:01:02 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/26 15:26:59 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# include <stdlib.h>
# include <fcntl.h>

# define FLAG_V				(1 << 0)
# define FLAG_C				(1 << 1)
# define FLAG_T				(1 << 2)
# define FLAG_O				(1 << 3)
# define FLAG_I				(1 << 4)
# define FLAG_R				(1 << 5)
# define FLAG_WRONG_INPUT	(1 << 6)
# define FLAG_HELP			(1 << 7)

typedef struct			s_stack
{
	int					number;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_options
{
	char				flags;
}						t_options;

/*
**===============================INPUT FUNCTIONS============================
*/
int						option_input(char **argv, int i, t_options *option);
int						double_input(char **argv);

void					valid_input(char **argv, int i);

/*
**===============================OPERATION FUNCTIONS============================
*/
int						sa_sb(t_stack **stack);
int						pa_pb(t_stack **stack_1, t_stack **stack_2);
int						ra_rb(t_stack **stack);
int						rra_rrb(t_stack **stack);

void					ss(t_stack **stack_a, t_stack **stack_b);
void					rr(t_stack **stack_a, t_stack **stack_b);
void					rrr(t_stack **stack_a, t_stack **stack_b);

/*
**===============================STACK FUNCTIONS===============================
*/
t_stack					*ft_newnode(int number);
t_stack					*ft_emptynode(void);

void					ft_stackaddfront(t_stack **stack, t_stack *new);
void					ft_stackaddback(t_stack **stack, t_stack *new);

/*
**===============================PRINTING FUNCTION=============================
*/
void					option_print(t_stack *stacks[2], t_options *option,
						char *line, int count);
void					print(t_stack *stack_a, t_stack *stack_b);

#endif
