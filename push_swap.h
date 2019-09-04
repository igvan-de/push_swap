/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 15:15:31 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/04 19:07:09 by igvan-de      ########   odam.nl         */
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

typedef struct 			s_median
{
	int					chunk1;
	int					chunk2;
	int					chunk3;
	int					chunk4;
}						t_median;

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
int					wich_chunk(t_stack **stack, t_median *max_int);

void				ft_stackaddfront(t_stack **alst, t_stack *new);
void				ft_stackaddback(t_stack **node, t_stack *new);
void				ft_delnode(t_stack *stack);
void				reverse(t_stack **stack);
void				median(t_stack *stack, t_median *max_int, int i);

void				algorithm(t_stack **stack_a, t_stack **stack_b, t_median *max_int, int i); // maybe need to delete
void				swap(t_stack **stack, t_median *max_int, int chunksize); //Check to make it static

t_stack 			*ft_newnode(int number);
t_stack 			*ft_emptynode(void);

void	test_print(t_stack *stack_a, t_stack *stack_b);//delte at the end