/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/04 19:07:36 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		shortest_start(t_stack *stack, int start, int end, t_value *value)
{
	t_stack 	*tmp;
	int			i;

	if (stack == NULL)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->number >= start && tmp->number <= end)
		{
			value->start = tmp->number;
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int		shortest_end(t_stack *stack, int start, int end, t_value *value)
{
	t_stack 	*tmp;
	int			i;

	if (stack == NULL)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->number >= start && tmp->number <= end)
		{
			value->end = tmp->number;
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void			swap(t_stack **stack, t_median *max_int, int chunksize)
{
	t_value		*value;
	int			big_start;
	int			big_end;

	value = (t_value*)ft_memalloc(sizeof(t_value));
	//PLACE THIS IN A FUNCTION TO ITTERATE TROUGH ALL CHUNKS
	big_start = shortest_start(*stack, 0, wich_chunk(stack, max_int)/*max_int->chunk1*/, value);
	reverse(stack);
	big_end = shortest_end(*stack, 0, wich_chunk(stack, max_int), value);
	reverse(stack);
	ft_printf("start = %d\n", value->start);
	ft_printf("end = %d\n", value->end);
	while (chunksize > 0)
	{
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

void			algorithm(t_stack **stack_a, t_stack **stack_b, t_median *max_int, int i)
{
	int			chunksize;
	int			chunk_amount;
	int			chunk_size_;

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
		# ifdef DEBUG
		ft_printf("chunkamount = %d\n", chunk_amount);
		# endif
		i = 0;
		while (i < chunk_size_)
		{
			swap(stack_a, max_int, chunksize);
			pa_pb(stack_a, stack_b);
			i++;
			test_print(*stack_a, *stack_b);
		}
		chunk_amount--;
	}
	// while (stack_b != NULL)
	// 	pa_pb(stack_b, stack_a);
	if (stack_a == NULL || stack_b == NULL) //ADDED STACK_A!!
		return ;
}
