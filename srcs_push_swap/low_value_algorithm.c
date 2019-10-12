/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   low_value_algorithm.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 13:21:58 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/12 15:22:07 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///////REMOVE!!!!!!!!

void		print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a;
	if (stack_a == NULL)
		return ;
	ft_printf("a = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
	if (stack_b == NULL)
		return ;
	tmp = stack_b;
	ft_printf("b = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

////////////

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

static int	check_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp= *stack_a;
	if (tmp->next == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->number > tmp->next->number)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void		low_value_algorithm(t_stack **stack_a, t_stack **stack_b, int i)
{
	int		count_start;
	int		count_end;
	int		lowest;

	if (stack_a == NULL)
		return ;
	if (check_sorted(stack_a) != 0)
	{
		lowest = find_lowest(stack_a);
		count_start = steps_to_lowest(stack_a);
		reverse(stack_a);
		count_end = steps_to_lowest(stack_a);
		reverse(stack_a);
		// ft_printf("start = %d\nend = %d\n", count_start, count_end);
	}
	while (i > 0)
	{
		if (check_sorted(stack_a) == 0 && stack_b == NULL)
			exit(0);
		if (check_sorted(stack_a) == -1)
		{
			if (count_start < count_end)
			{
				pa_pb(stack_a, stack_b);
				ft_printf("pa\n");
			}
			if (count_start > count_end)
			{
				rra_rrb(stack_a);
				ft_printf("rra\n");
				if (check_sorted(stack_a) == -1)
				{
					pa_pb(stack_a, stack_b);
					ft_printf("pa\n");
				}
			}
		}
		if (check_sorted(stack_a) == 0 && stack_b != NULL)
		{
			pa_pb(stack_b, stack_a);
			ft_printf("pb\n");
		}	
		else if ((*stack_a)->number > (*stack_a)->next->number)
		{
			sa_sb(stack_a);
			ft_printf("sa\n");
		}
		i--;
	}
	// print_stacks(*stack_a, *stack_b);
}