/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   low_value_algorithm.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 13:21:58 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/27 18:13:46 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			steps_to_lowest(t_stack **stack_a)
{
	t_stack *tmp;
	int		counter;
	int		value;

	tmp = *stack_a;
	counter = 0;
	value = search_lowest(stack_a);
	while (tmp)
	{
		if (tmp->number == value)
			return (counter);
		tmp = tmp->next;
		counter++;
	}
	return (0);
}

static void	bigger_then_three(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		value_start;
	int		value_end;
	int		lowest;

	while (i >= 0)
	{
		if (check_sorted(stack_a) == -1)
		{
			lowest = search_lowest(stack_a);
			give_value(stack_a, &value_start, &value_end);
			if (value_start <= value_end)
				lowest_start(stack_a, stack_b, lowest);
			if (value_start > value_end)
				lowest_end(stack_a, stack_b, lowest);
		}
		while (check_sorted(stack_a) == 0 && *stack_b != NULL)
		{
			pa_pb(stack_b, stack_a);
			ft_printf("pa\n");
		}
		i--;
	}
}

static void	lower_then_three(t_stack **stack_a, int i)
{
	int		value_start;
	int		value_end;
	int		lowest;

	while (i > 0)
	{
		if (check_sorted(stack_a) == -1)
		{
			give_value(stack_a, &value_start, &value_end);
			if ((*stack_a)->number == lowest)
				lowest_at_beginning(stack_a, lowest);
			else
			{
				lowest = search_lowest(stack_a);
				lowest_not_at_beginning(stack_a, lowest, value_start,
				value_end);
			}
		}
		i--;
	}
}

void		low_value_algorithm(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (stack_a == NULL)
		return ;
	if (i > 3)
		bigger_then_three(stack_a, stack_b, i);
	else
		lower_then_three(stack_a, i);
}
