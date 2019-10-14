/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 17:48:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/14 17:58:28 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_lowest(t_stack **stack_a)
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

int		search_highest(t_stack **stack_a)
{
	t_stack *tmp;
	int		value;

	tmp = *stack_a;
	value = tmp->number;
	while (tmp)
	{
		if (tmp->number > value)
			value = tmp->number;
		tmp = tmp->next;
	}
	return (value);
}

int		search_next_lowest(t_stack **stack_a, int lowest)
{
	t_stack	*tmp;
	int		next_lowest;
	int		highest;

	tmp = *stack_a;
	highest = search_highest(stack_a);
	while (tmp)
	{
		if (tmp->number > lowest && tmp->number < highest)
		{
			next_lowest = tmp->number;
			return (next_lowest);
		}
		tmp = tmp->next;
	}
	return (0);
}
