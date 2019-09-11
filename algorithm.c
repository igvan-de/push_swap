/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/11 12:24:57 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		shortest_steps_start(t_stack *stack, int start, int end, t_value *value)
{
	t_stack 	*tmp;
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
static int		shortest_steps_end(t_stack *stack, int start, int end, t_value *value)
{
	t_stack 	*tmp;
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

static void			swap(t_stack **stack, t_chunk *chunk, int chunksize, t_value *value)
{
	int			big_start;
	int			big_end;

	big_start = shortest_steps_start(*stack, chunk->lowest_value, chunk->max_chunk_value, value);
	reverse(stack);
	big_end = shortest_steps_end(*stack, chunk->lowest_value, chunk->max_chunk_value, value);
	reverse(stack);
	while (chunksize > 0)
	{
		#ifdef DEBUG
			ft_printf("start = %d\n end = %d\n", value->start, value->end);
			ft_printf("big_start = %d\n big_end = %d\n", big_start, big_end);
		#endif
		if (big_start == 0)
			break ;
		if (big_start <= big_end && (value->start < value->end || value->start == value->end))
		{
			while (big_start > 0)
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
	//Need to initialize all ints of structs on 0 value!!!
	// value->start = 0; 
	// value->end = 0;
	chunksize = size_chunk(i);
	chunk_amount = calculate_chunk_amount(chunksize, i);
	chunk_size_ = chunksize;
	while (chunk_amount > 0)
	{
		i = 0;
		chunk_value(stack_a, chunk, chunksize);//statement for empty list!
		while (i < chunk_size_)
		{
			swap(stack_a, chunk, chunksize, value);
			pa_pb(stack_a, stack_b);
			i++;
			if ((*stack_b)->next != NULL)
			{
				ft_printf("number = %d\nnext number = %d\n", (*stack_b)->number ,(*stack_b)->next->number);
				if ((*stack_b)->number < (*stack_b)->next->number)
					sa_sb(stack_b);
			}
			test_print(*stack_a, *stack_b);
		}
		chunk_amount--;
	}
	push_back(stack_a, stack_b, chunk, value);
	ft_printf("counter = %d\n", value->counter);
}
