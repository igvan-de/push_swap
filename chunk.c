/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:31:01 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/04 19:01:09 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		size_chunk(int i)
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

int		wich_chunk(t_stack **stack, t_median *max_int)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->number <= max_int->chunk1)
			return (max_int->chunk1);
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->number <= max_int->chunk2)
			return (max_int->chunk2);
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->number <= max_int->chunk3)
			return (max_int->chunk3);
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->number <= max_int->chunk4)
			return (max_int->chunk4);
		tmp = tmp->next;
	}
	return (0);
}
