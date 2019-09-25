/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 14:18:00 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/25 15:44:19 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_stack_a(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (stack == NULL)
		return ;
	ft_printf("a = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

static void	print_stack_b(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (stack == NULL)
		return ;
	ft_printf("b = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

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

void		special_print(t_stack *stacks[2], t_options *option,
			char *line, int count)
{
	if (option->o_argv == 1)
		ft_printf("%s\n", line);
	if (option->i_argv == 1 && option->wrong_input == 0)
	{
		ft_printf(COLOR_DARK_GRAY"====== STEP %d ======\n", count);
		ft_printf(COLOR_RESET);
	}
	if (option->v_argv == 1)
	{
		if (option->c_argv == 1)
		{
			ft_printf(COLOR_WHITE);
			print_stack_a(stacks[0]);
			ft_printf(COLOR_RESET);
			ft_printf(COLOR_BOLD_BLUE);
			print_stack_b(stacks[1]);
			ft_printf(COLOR_RESET);
		}
		else
			print(stacks[0], stacks[1]);
	}
	if (option->t_argv == 1)
		sleep(1);
}
