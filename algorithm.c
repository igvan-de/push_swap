/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/28 15:01:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		shortest_start(t_stack *stack)
{
	t_stack *tmp;
	int		i;

	if (stack == NULL)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->number >= 0 && tmp->number <= 19)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int		shortest_end(t_stack *stack)
{
	t_stack *tmp;
	int		i;

	if (stack == NULL)
		return (0);
	tmp = stack;
	i = 0;
	stack = tmp;
	while (tmp->next != NULL)
	{
		if (tmp->number >= 0 && tmp->number <= 19)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void			smallest_chunk(t_stack **stack,	/*t_chunksize	*chunk*/int chunk_size)
{
	int			big_start;
	int			big_end;

	big_start = shortest_start(*stack);
	reverse(stack);
	big_end = shortest_end(*stack);
	reverse(stack);
	ft_printf("chunksize = %d\nbig start = %d\nbig_end = %d\n", chunk_size, big_start, big_end);
	while (/*chunk->size*/chunk_size > 0)
	{
		if (big_start <= big_end)
		{
			while (big_start > 0)
			{
				ra_rb(stack);
				big_start--;
			}
		}
		else if (big_start > big_end)
		{	
			while (big_end > 0)
			{
				rra_rrb(stack);
				big_end--;
			}
		}
		/*chunk->size*/chunk_size--;
	}
}

void			algorithm(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_chunksize chunksize;
	int			chunck_amount;
	int			chunk_size_;

	chunck_amount = 0;
	size_chunk(i, &chunksize);
	if (i < 100)
	{
		if (i % 5 == 0)
			chunck_amount = i / chunksize.size;
		else
			chunck_amount = i / chunksize.size + 1;
	}
	else if (i > 100)
	{
		if (i % 11 == 0)
			chunck_amount = i / chunksize.size;
		else
			chunck_amount = i / chunksize.size + 1;
	}
	ft_printf("chunksize = %d\n", chunksize.size);
	ft_printf("chunkamount = %d\n", chunck_amount);
	chunk_size_ = chunksize.size;
	while (chunck_amount > 0)
	{
		i = 0;
		while (i < chunk_size_)
		{
			smallest_chunk(stack_a, /*&chunksize*/chunksize.size);
			pa_pb(stack_a, stack_b);
			i++;
		}
		chunck_amount--;
	}
	if (stack_b == NULL)
		return ;
}
