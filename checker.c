/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/06 17:42:35 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print(t_stack *stack_a, t_stack *stack_b)
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
	tmp = stack_b;
	ft_printf("b = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

static int	valid_input(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
		exit (0);
	while (i < argc)
	{
		argv++;
		if (ft_isnum(*argv) == 0)
		{
			ft_printf("ERROR\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

int	checker_sort(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number <= stack->next->number)
			stack = stack->next;
		else
			return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*new_stack_a;
	t_chunk		*chunk;
	int 		i;

	i = 1;
	valid_input(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	chunk = NULL;
	chunk = (t_chunk*)ft_memalloc(sizeof(t_chunk));
	while (argv[i])
	{
		new_stack_a = ft_newnode(ft_atoi(argv[i]));
		if (new_stack_a == NULL)
			return (0);
		ft_stackaddback(&stack_a, new_stack_a);
		i++;
	}
	//checker_commands(&stack_a, &stack_b);
	algorithm(&stack_a, &stack_b, chunk, i - 1);
	test_print(stack_a, stack_b);
	if (checker_sort(stack_a) == 1)
	{
		ft_printf("KO\n");
		exit (0);
	}
	else if (checker_sort(stack_a) == 0)
		ft_printf("OK\n");
	return (0);
}
