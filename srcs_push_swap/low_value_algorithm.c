/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   low_value_algorithm.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 13:21:58 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/10 16:42:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lowest(t_stack **stack_a)
{
	t_stack *tmp;
	int		value;

	tmp = *stack_a;
	value = tmp->number;
	while (tmp)
	{
		if (tmp->number < value)
			value = tmp->number;
		tmp = tmp->next;
	}
	return (value);
}

static int	steps_to_lowest(t_stack **stack_a)
{
	t_stack *tmp;
	int		counter;
	int		value;

	tmp = *stack_a;
	counter = 0;
	value = find_lowest(stack_a);	
	while (tmp)
	{
		if (tmp->number == value)
			return (counter);
		tmp = tmp->next;
		counter++;
	}
	return (0);
}

void		low_value_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		count_start;
	int		count_end;
	int		lowest;

	tmp = *stack_a;
	if (stack_a == NULL)
		return ;
	lowest = find_lowest(stack_a);
	count_start = steps_to_lowest(stack_a);
	reverse(stack_a);
	count_end = steps_to_lowest(stack_a);
	reverse(stack_a);
	ft_printf("start = %d\nend = %d\n", count_start, count_end);
	while(tmp)
	{
		if (count_start < count_end)
		{
			ra_rb(stack_a);
			ft_printf("ra\n");
			// check_sorted();
		}
		if (count_start > count_end)
		{
			rra_rrb(stack_a);
			ft_printf("rra\n");
		}
		tmp = tmp->next;
	}
	stack_b = NULL;
}