/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 14:18:00 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/18 17:55:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print(t_stack *stack_a, t_stack *stack_b)
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

void			color_print(t_stack *stack_a, t_stack *stack_b, char **argv, int count)
{
	if (ft_strequ(*argv, "-c") == 1)
	{
		ft_printf(COLOR_BOLD_YELLOW);
		print(stack_a, stack_b);
		ft_printf(COLOR_RESET);
	}
	if (ft_strequ(*argv, "-i") == 1)
	{
		ft_printf(COLOR_WHITE"==== STEP %d ====\n", count);
		ft_printf(COLOR_RESET);
		print(stack_a, stack_b);
	}
	if (ft_strequ(*argv, "-ic") == 1)
	{
		ft_printf(COLOR_WHITE"==== STEP %d ====\n", count);
		ft_printf(COLOR_RESET);
		ft_printf(COLOR_BOLD_YELLOW);
		print(stack_a, stack_b);
		ft_printf(COLOR_RESET);
	}
}
