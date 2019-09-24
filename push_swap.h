/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 15:15:31 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/24 09:12:13 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/includes/libft.h"
# include "./Printf/ft_printf.h"
# include <stdlib.h>

typedef struct			s_stack
{
	int					number;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_chunk
{
	int					max_chunk_value;
	int					lowest_value;
	int					highest_value;
}						t_chunk;

typedef struct			s_value
{
	int					start;
	int					end;
}						t_value;

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

void					ft_stackaddfront(t_stack **alst, t_stack *new);
void					ft_stackaddback(t_stack **node, t_stack *new);
void					ft_delnode(t_stack *stack);
void					reverse(t_stack **stack);

/*
**===============================CHUNK FUNCTIONS===============================
*/
int						size_chunk(int i);
int						calculate_chunk_amount(int chuksize, int i);

void					chunk_value(t_stack **stack, t_chunk *chunk,
						int chunksize);
void					find_highest(t_stack *stack, t_chunk *chunk);

/*
**===============================ALGORITHM FUNCTIONS===========================
*/
void					algorithm(t_stack **stack_a, t_stack **stack_b,
						t_chunk *chunk, int i);
void					push_back(t_stack **stack_a, t_stack **stack_b,
						t_chunk *chunk);

/*
**=============================CHECK CONDITION FUNCTIONS========================
*/
void					conditions_push_back(t_stack **stack_b, int start,
						int end);
void					conditions_stack_b(t_stack **stack_b);
void					conditions_start_end(t_stack **stack, int big_start,
						int big_end, t_value *value);

/*
**===============================PRINTING FUNCTION=============================
*/
void					print(t_stack *stack_a, t_stack *stack_b);

#endif
