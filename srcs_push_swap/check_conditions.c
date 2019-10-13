/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_conditions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:21:06 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/13 15:40:28 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conditions_start_end(t_stack **stack, int big_start,
		int big_end, t_value *value)
{
	if (big_start <= big_end && (value->start <= value->end))
	{
		while (big_start > 0)
		{
			ra_rb(stack);
			ft_printf("ra\n");
			big_start--;
		}
	}
	else if (big_start > big_end || value->start > value->end)
	{
		while (big_end >= 0)
		{
			rra_rrb(stack);
			ft_printf("rra\n");
			big_end--;
		}
	}
}

void	conditions_stack_b(t_stack **stack_b)
{
	if ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->number < (*stack_b)->next->number)
		{
			sa_sb(stack_b);
			ft_printf("sb\n");
		}
	}
}

void	conditions_push_back(t_stack **stack_b, int start, int end)
{
	if (start <= end)
	{
		while (start > 0)
		{
			ra_rb(stack_b);
			ft_printf("rb\n");
			start--;
		}
	}
	else if (end < start)
	{
		while (end >= 0)
		{
			rra_rrb(stack_b);
			ft_printf("rrb\n");
			end--;
		}
	}
}

void	is_sorted(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
		{
			i++;
			if (argv[i + 1] == '\0')
				exit(0);
		}
		else
			break ;
	}
}
