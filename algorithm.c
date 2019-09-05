/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/05 18:56:47 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		shortest_start(t_stack *stack, int start, int end, t_value *value)
{
	t_stack 	*tmp;
	int			counter;

	if (stack == NULL)
		return (0);
	tmp = stack;
	counter = 0;
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->number >= start && tmp->number <= end)
		{
			value->start = tmp->number;
			return (counter);
		}
		tmp = tmp->next;
		counter++;
	}
	return (0);
}

static int		shortest_end(t_stack *stack, int start, int end, t_value *value)
{
	t_stack 	*tmp;
	int			counter;

	if (stack == NULL)
		return (0);
	tmp = stack;
	counter = 0;
	while (tmp->next != NULL)
	{
		// ft_printf("number = %d\n end = %d\n", tmp->number, value->end);
		if (tmp->number >= start && tmp->number <= end)
		{
			value->end = tmp->number;
			ft_printf("number = %d\n end = %d\n", tmp->number, value->end);
			return (counter);
		}
		tmp = tmp->next;
		counter++;
	}
	return (0);
}

void			swap(t_stack **stack, t_chunk *chunk, int chunksize)
{
	t_value		*value;
	int			big_start;
	int			big_end;

	value = (t_value*)ft_memalloc(sizeof(t_value));
	chunk_value(stack, chunk, chunksize);
	big_start = shortest_start(*stack, chunk->lowest_value, chunk->max_chunk_value, value);
	reverse(stack);
	big_end = shortest_end(*stack, chunk->lowest_value, chunk->max_chunk_value, value);
	reverse(stack);
	while (chunksize > 0)
	{
		// ft_printf("start = %d\n", value->start);
		// ft_printf("end = %d\n", value->end);
		if (big_start <= big_end && value->start < value->end)
		{
			while (big_start >= 0)
			{
				ra_rb(stack);
				big_start--;
			}
		}
		else if (big_start > big_end || value->start > value->end)
		{	
			while (big_end >= 0)
			{
				rra_rrb(stack);
				big_end--;
			}
		}
		chunksize--;
	}
}

void			algorithm(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk, int i)
{
	int			chunksize;
	int			chunk_amount;
	int			chunk_size_;//change name!!!

	chunk_amount = 0;
	chunksize = size_chunk(i);
	if (i < 100)
	{
		if (i % 5 == 0)
			chunk_amount = i / chunksize;
		else
			chunk_amount = i / chunksize + 1;
	}
	else if (i > 100)
	{
		if (i % 11 == 0)
			chunk_amount = i / chunksize;
		else
			chunk_amount = i / chunksize + 1;
	}
	chunk_size_ = chunksize;
	while (chunk_amount > 0)
	{
		i = 0;
		while (i < chunk_size_)
		{
			swap(stack_a, chunk, chunksize);
			pa_pb(stack_a, stack_b);
			i++;
			test_print(*stack_a, *stack_b);
		}
		chunk_amount--;
	}
	while (stack_b != NULL)
	{
		if ((*stack_b)->number < (*stack_b)->next->number)
			ra_rb(stack_b);
		else
			pa_pb(stack_b, stack_a);
		stack_b = &(*stack_b)->next;
	}
}
