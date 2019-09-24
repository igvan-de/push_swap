/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:01:02 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/24 09:38:07 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./Libft/includes/libft.h"
# include "./Libft/includes/get_next_line.h"
# include "./Printf/ft_printf.h"

# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_stack
{
	int					number;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_options
{
	int					v_argv;
	int					c_argv;
	int					t_argv;
	int					o_argv;
	int					i_argv;
	int					r_argv;
	int					wrong_input;
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
void					special_print(t_stack *stacks[2], t_options *option,
						char *line, int count);
void					print(t_stack *stack_a, t_stack *stack_b);

#endif
