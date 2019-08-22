/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:58:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/22 16:58:33 by igvan-de      ########   odam.nl         */
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
		ft_printf("tmp = %d\n", tmp->number);
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
	reverse(&tmp);
	while (tmp->next != NULL)
	{
		ft_printf("tmp = %d\n", tmp->number);
		if (tmp->number >= 0 && tmp->number <= 19)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void			smallest_chunk(t_stack **stack,	t_chunksize	*cnksize)
{
	int			chunksize;

	ft_printf("%d\n", (*stack)->next->number);
	chunksize = cnksize->size;
	while (chunksize > 0)
	{
		if (shortest_start(*stack) <= shortest_end(*stack))
			ra_rb(stack);
		else if (shortest_start(*stack) > shortest_end(*stack))
			rra_rrb(stack);
		chunksize--;
	}
}

void			algorithm(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_chunksize chunksize;
	
	size_chunk(i, &chunksize);
	smallest_chunk(stack_a, &chunksize);
	if (stack_b == NULL)
		return ;
}