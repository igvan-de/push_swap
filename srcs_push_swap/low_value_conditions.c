/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   low_value_conditions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 15:24:48 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/27 18:14:42 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lowest_start(t_stack **stack_a, t_stack **stack_b, int lowest)
{
	if ((*stack_a)->number == lowest)
	{
		pa_pb(stack_a, stack_b);
		ft_printf("pb\n");
		return ;
	}
	while ((*stack_a)->number != lowest)
	{
		if ((*stack_a)->next->number == lowest)
		{
			sa_sb(stack_a);
			ft_printf("sa\n");
		}
		else
		{
			ra_rb(stack_a);
			ft_printf("ra\n");
		}
		if ((*stack_a)->number == lowest)
		{
			pa_pb(stack_a, stack_b);
			ft_printf("pb\n");
			return ;
		}
	}
}

void	lowest_end(t_stack **stack_a, t_stack **stack_b, int lowest)
{
	while ((*stack_a)->number != lowest)
	{
		rra_rrb(stack_a);
		ft_printf("rra\n");
		if ((*stack_a)->number == lowest)
		{
			pa_pb(stack_a, stack_b);
			ft_printf("pb\n");
			return ;
		}
	}
}

void	give_value(t_stack **stack_a, int *value_start,
		int *value_end)
{
	*value_start = steps_to_lowest(stack_a);
	reverse(stack_a);
	*value_end = steps_to_lowest(stack_a);
	reverse(stack_a);
}

void	lowest_at_beginning(t_stack **stack_a, int lowest)
{
	int lowest_next;

	lowest_next = search_next_lowest(stack_a, lowest);
	if ((*stack_a)->next->number == lowest_next)
	{
		sa_sb(stack_a);
		ft_printf("sa\n");
	}
	reverse(stack_a);
	if ((*stack_a)->number == lowest_next)
	{
		reverse(stack_a);
		rra_rrb(stack_a);
		ft_printf("rra\n");
	}
	else
		reverse(stack_a);
}

void	lowest_not_at_beginning(t_stack **stack_a, int lowest,
		int value_start, int value_end)
{
	if (value_start <= value_end)
	{
		if ((*stack_a)->next->number == lowest)
		{
			sa_sb(stack_a);
			ft_printf("sa\n");
		}
	}
	if (value_start > value_end)
	{
		reverse(stack_a);
		if ((*stack_a)->number == lowest)
		{
			reverse(stack_a);
			rra_rrb(stack_a);
			ft_printf("rra\n");
		}
		else
			reverse(stack_a);
	}
}
