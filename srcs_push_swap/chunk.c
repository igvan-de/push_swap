/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:31:01 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/25 15:45:05 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_smallest(t_stack *stack, t_chunk *chunk)
{
	chunk->lowest_value = stack->number;
	while (stack != NULL)
	{
		if (stack->number < chunk->lowest_value)
			chunk->lowest_value = stack->number;
		stack = stack->next;
	}
}

void		find_highest(t_stack *stack, t_chunk *chunk)
{
	chunk->highest_value = stack->number;
	while (stack != NULL)
	{
		if (stack->number > chunk->highest_value)
			chunk->highest_value = stack->number;
		stack = stack->next;
	}
}

int			size_chunk(int i)
{
	int		chunksize;

	chunksize = 0;
	if (i <= 100)
	{
		if (i % 5 == 0)
			chunksize = i / 5;
		else
			chunksize = i / 5 + 1;
	}
	if (i > 100)
	{
		if (i % 11 == 0)
			chunksize = i / 11;
		else
			chunksize = i / 11 + 1;
	}
	return (chunksize);
}

int			calculate_chunk_amount(int chunksize, int i)
{
	int		chunk_amount;

	chunk_amount = 0;
	if (i % chunksize == 0)
		chunk_amount = i / chunksize;
	else
		chunk_amount = i / chunksize + 1;
	return (chunk_amount);
}

void		chunk_value(t_stack **stack, t_chunk *chunk, int chunksize)
{
	t_stack	*probe;
	int		i;
	int		previous;

	probe = *stack;
	i = 1;
	find_smallest(*stack, chunk);
	find_highest(*stack, chunk);
	previous = chunk->lowest_value;
	chunk->max_chunk_value = probe->number;
	while (i < chunksize)
	{
		probe = *stack;
		chunk->max_chunk_value = chunk->highest_value;
		while (probe != NULL)
		{
			if (probe->number < chunk->max_chunk_value
				&& probe->number > previous)
				chunk->max_chunk_value = probe->number;
			probe = probe->next;
		}
		previous = chunk->max_chunk_value;
		i++;
	}
}
