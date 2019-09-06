/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 15:15:31 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/06 17:37:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/includes/libft.h"
#include "./Libft/includes/get_next_line.h" //Not sure if this is needed. CHECK LATER!!!
#include "./Printf/ft_printf.h"

#include <stdlib.h>
// #define DEBUG

typedef struct 			s_stack
{
	int					number;
	struct s_stack		*next;
}             			t_stack;

typedef struct 			s_chunk
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


int					sa_sb(t_stack **stack);
int					pa_pb(t_stack **stack_1, t_stack **stack_2);
int					ra_rb(t_stack **stack);
int					rra_rrb(t_stack **stack);
int					size_chunk(int i);
int					calculate_chunk_amount(int chuksize, int i);
int					checker_sort(t_stack *stack);

void				ft_stackaddfront(t_stack **alst, t_stack *new);
void				ft_stackaddback(t_stack **node, t_stack *new);
void				ft_delnode(t_stack *stack);
void				reverse(t_stack **stack);
void				chunk_value(t_stack **stack, t_chunk *chunk, int chunksize);

void				algorithm(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk, int i); // maybe need to delete

t_stack 			*ft_newnode(int number);
t_stack 			*ft_emptynode(void);

void				test_print(t_stack *stack_a, t_stack *stack_b);//delte at the end