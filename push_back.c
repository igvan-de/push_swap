/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 15:46:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/11 11:51:51 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int      counter(t_stack *stack, int biggest)
{
	int		counter;

	counter = 0;
	while (stack->number < biggest)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void			push_back(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk, t_value *value)
{
	t_stack	*prob;
	int		start;
	int		end;
	int		i;

	prob = *stack_b;
	i = 0;
	while (prob != NULL)
	{
		prob = prob->next;
		i++;
	}
	while (i > 0)
	{
		find_highest(*stack_b, chunk);
		start = counter(*stack_b, chunk->highest_value);
		reverse(stack_b);
		end = counter(*stack_b, chunk->highest_value);
		reverse(stack_b);
		if (start <= end)
		{
			while (start > 0)
			{
				ra_rb(stack_b);
				start--;
				value->counter++;
			}
		}
		else if (end < start)
		{
			while (end >= 0)
			{
				rra_rrb(stack_b);
				end--;
				value->counter++;
			}
		}
		pa_pb(stack_b, stack_a);
		value->counter++;
		i--;
	}
}
//check if rr is possible!!!!!