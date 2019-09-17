/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 16:08:27 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/17 17:26:34 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a;
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

int		is_sorted(t_stack *stack)
{
	t_stack	*prob;

	prob = stack;
	while (prob)
	{
		if (prob->next != NULL)
		{
			if (prob->number > prob->next->number)
				return (1);
		}
		prob = prob->next;
	}
	return (0);
}
