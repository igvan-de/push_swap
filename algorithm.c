/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/09 17:36:35 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check to delete shortest_start or end!!!!!!!!!!!
static int		shortest_steps(t_stack *stack, int start, int end, t_value *value)
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
			// ft_printf("number = %d\n start = %d\n", tmp->number, value->start);
			return (counter);
		}
		tmp = tmp->next;
		counter++;
	}
	return (0);
}

static void			swap(t_stack **stack, t_chunk *chunk, int chunksize, t_value *value)
{
	int			big_start;
	int			big_end;

	big_start = shortest_steps(*stack, chunk->lowest_value, chunk->max_chunk_value, value);
	reverse(stack);
	big_end = shortest_steps(*stack, chunk->lowest_value, chunk->max_chunk_value, value);
	reverse(stack);
	while (chunksize > 0)
	{
		#ifdef DEBUG
			ft_printf("start = %d\n end = %d\n", value->start, value->end);
		#endif
		// if (checker_sort(*stack) == 0)
		// 	break ;
		if (big_start <= big_end && value->start < value->end)
		{
			while (big_start >= 0)
			{
				ra_rb(stack);
				big_start--;
				value->counter++;
			}
		}
		else if (big_start > big_end || value->start > value->end)
		{	
			while (big_end >= 0)
			{
				rra_rrb(stack);
				big_end--;
				value->counter++;
			}
		}
		chunksize--;
	}
}

void			algorithm(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk, int i)
{
	t_value		*value;
	int			chunksize;
	int			chunk_amount;
	int			chunk_size_;//change name!!!

	value = (t_value*)ft_memalloc(sizeof(t_value));
	chunksize = size_chunk(i);
	chunk_amount = calculate_chunk_amount(chunksize, i);
	chunk_size_ = chunksize;
	while (chunk_amount > 0)
	{
		i = 0;
		chunk_value(stack_a, chunk, chunksize);//statement for empty list!
		while (i < chunk_size_)
		{
			// if (checker_sort(*stack_a) == 0)
			// 	break ;
			swap(stack_a, chunk, chunksize, value);
			pa_pb(stack_a, stack_b);
			i++;
			test_print(*stack_a, *stack_b);
		}
		chunk_amount--;
	}
	push_back(stack_a, stack_b, chunk, value);
	ft_printf("counter = %d\n", value->counter);
	//function to sort stack_b
}
