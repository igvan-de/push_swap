/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:31:01 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/05 18:13:32 by igvan-de      ########   odam.nl         */
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

static void	find_highest(t_stack *stack, t_chunk *chunk)
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
	if (i < 100)
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

void		chunk_value(t_stack **stack, t_chunk *chunk, int chunksize)
{
	t_stack	*probe;
	int		i;

	probe = *stack;
	i = 0;
	chunk->max_chunk_value = probe->number;
	find_smallest(*stack, chunk);
	find_highest(*stack, chunk);
	while (i < chunksize)
	{
		probe = *stack;
		while (probe != NULL)
		{
			if (probe->number < chunk->max_chunk_value && probe->number > chunk->lowest_value)
				chunk->max_chunk_value = probe->number;
			probe = probe->next;
		}
		i++;
	}
	# ifdef DEBUG
		ft_printf("max_chunk_value = %d\n", chunk->max_chunk_value);
		ft_printf("lowest_value = %d\n", chunk->lowest_value);
		ft_printf("highest_value = %d\n", chunk->highest_value);
	# endif
}

// int		wich_chunk(t_stack **stack)//, t_chunk *chunk)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->number <= chunk->chunk1)
// 			return (chunk->chunk1);
// 		tmp = tmp->next;
// 	}
// 	tmp = *stack;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->number <= chunk->chunk2)
// 			return (chunk->chunk2);
// 		tmp = tmp->next;
// 	}
// 	tmp = *stack;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->number <= chunk->chunk3)
// 			return (chunk->chunk3);
// 		tmp = tmp->next;
// 	}
// 	tmp = *stack;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->number <= chunk->chunk4)
// 			return (chunk->chunk4);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
