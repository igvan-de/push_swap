/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 14:13:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/12 16:12:06 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa_sb(t_stack **stack)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return (0);
	ft_swap(&(*stack)->number, &(*stack)->next->number);
	return (0);
}

int		pa_pb(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*node2;

	if (*stack_1 == NULL)
		return (0);
	node2 = (*stack_1)->next;
	ft_stackaddfront(stack_2, *stack_1);
	*stack_1 = node2;
	return (0);
}

int		ra_rb(t_stack **stack)
{
	t_stack	*node2;

	if (*stack == NULL)
		return (0);
	node2 = (*stack)->next;
	ft_stackaddback(stack, *stack);
	(*stack)->next = NULL;	//To make sure that ->next doens't point to something else the NULL to make sure a infinite loop is bypassed
	*stack = node2;
	return (0);
}

int		rra_rrb(t_stack **stack)
{
	t_stack	*lastnode;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	lastnode = *stack;
	while (lastnode->next->next != NULL)
		lastnode = lastnode->next;
	ft_stackaddfront(stack, lastnode->next);
	lastnode->next = NULL;
	return (0);
}























































// size = argc 

// stack a = malloc argc * size of int *

// int array[1000]

// print array[500]

// int stack_a[10];
// int stack_b[10];

// char *str "hallo"

// int size = stack_a[10];

// ft_putchar(str[3]);
// j = size / 2;
// stack_b[0] = stack_a[j];
// stack_b->node = a; 


// a   b
// 1	0
// 2	0
// 3	0
// 4	0
// 5	0

// t_stack_a stack(t_stack_a a)
// {
// 	t_stack_a fiets;

// 	fiets->a = argv[0];

// }

// while (stack_a->node->next != NULL)
// {
// 	if (stack_a->node->next == NULL)
// 		stack_b->node = stack_a->node;
// 	stack_a->node = stack_a->node->next;
// }


// stack_b[0] = stack_a[2];
// stack_a[2] = stack_a[3];
// stack_a[3] = stack_a[4];