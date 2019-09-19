/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 14:13:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/19 15:49:20 by igvan-de      ########   odam.nl         */
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
	ft_stackaddback(&node2, *stack);
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
