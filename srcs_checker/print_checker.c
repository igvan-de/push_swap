/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 14:18:00 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/27 13:26:33 by igvan-de      ########   odam.nl         */
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

static int	print_help(void)
{
	ft_printf(COLOR_WHITE);
	ft_printf("-v = display stack(s) status\n");
	ft_printf("-c = display stack(s) in colors\n");
	ft_printf("-t = display stack(s) with in a slower pace\n");
	ft_printf("-o = display operations used to swap stack(s)\n");
	ft_printf("-i = display amount of steps\n");
	ft_printf("-r = displays end result of all operations\n");
	ft_printf(COLOR_RESET);
	exit(0);
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

void		option_print(t_stack *stack_a, t_stack *stack_b, t_options *option,
			char *line)
{
	if (option->flags & FLAG_HELP)
		print_help();
	if (option->flags & FLAG_I && !(option->flags & FLAG_WRONG_INPUT))
	{
		ft_printf(COLOR_DARK_GRAY"====== STEP %d ======\n", option->count);
		ft_printf(COLOR_RESET);
	}
	if (option->flags & FLAG_O)
		ft_printf("%s\n", line);
	if (option->flags & FLAG_V)
	{
		if (option->flags & FLAG_C)
		{
			ft_printf(COLOR_WHITE);
			print_stack_a(stack_a);
			ft_printf(COLOR_RESET);
			ft_printf(COLOR_BOLD_BLUE);
			print_stack_b(stack_b);
			ft_printf(COLOR_RESET);
		}
		else
			print(stack_a, stack_b);
	}
	if (option->flags & FLAG_T)
		sleep(1);
}
