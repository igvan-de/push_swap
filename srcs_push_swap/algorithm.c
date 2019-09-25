/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/25 14:31:07 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	shortest_steps_start(t_stack *stack, int start,
			int end, t_value *value)
{
	t_stack		*tmp;
	int			counter;

	tmp = stack;
	counter = 0;
	if (stack == NULL)
		return (0);
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
	return (counter);
}

static int	shortest_steps_end(t_stack *stack, int start,
			int end, t_value *value)
{
	t_stack		*tmp;
	int			counter;

	tmp = stack;
	counter = 0;
	if (stack == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->number >= start && tmp->number <= end)
		{
			value->end = tmp->number;
			return (counter);
		}
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}

static void	swap(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk,
			t_value *value)
{
	int			big_start;
	int			big_end;

	big_start = shortest_steps_start((*stack_a), chunk->lowest_value,
				chunk->max_chunk_value, value);
	reverse(stack_a);
	big_end = shortest_steps_end(*stack_a, chunk->lowest_value,
				chunk->max_chunk_value, value);
	reverse(stack_a);
	conditions_start_end(stack_a, big_start, big_end, value);
	if ((*stack_a)->next != NULL)
	{
		pa_pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void		algorithm(t_stack **stack_a, t_stack **stack_b,
			t_chunk *chunk, int i)
{
	t_value		*value;
	int			chunksize;
	int			chunk_amount;

	value = (t_value*)ft_memalloc(sizeof(t_value));
	chunksize = size_chunk(i);
	chunk_amount = calculate_chunk_amount(chunksize, i);
	while (chunk_amount > 0)
	{
		i = 0;
		if (stack_a != NULL)
			chunk_value(stack_a, chunk, chunksize);
		while (i < chunksize)
		{
			swap(stack_a, stack_b, chunk, value);
			conditions_stack_b(stack_b);
			i++;
		}
		chunk_amount--;
	}
	push_back(stack_a, stack_b, chunk);
	free(value);
}
