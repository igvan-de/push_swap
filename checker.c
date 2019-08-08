/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/08 17:38:30 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_print(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a;
	ft_printf("a = ");
	if (tmp->next == NULL)
		ft_printf("%d ", tmp->number);
	while (tmp->next != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
		if (tmp->next == NULL)
			ft_printf("%d ", tmp->number);
	}
	ft_printf("\n");
	tmp = stack_b;
	ft_printf("b = ");
	if (tmp->next == NULL)
		ft_printf("%d ", tmp->number);
	while (tmp->next != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
		if (tmp->next == NULL)
			ft_printf("%d ", tmp->number);
	}
	ft_printf("\n");
}

static void	checker_commands(t_stack **stack_a, t_stack **stack_b)
{
	// if (ft_strcmp(stack_a, "sa"))
	// 	sa_sb(stack_a);
	// // if (ft_strcmp(*argv, "sb"))
	// 	sa_sb(stack_b);
	// // if (ft_strcmp(*argv, "ss"))
	// 	sa_sb(stack_a);
	// 	sa_sb(stack_b);
	// if (ft_strcmp(*argv, "pa"))
		pa(stack_a, stack_b);
	// if (ft_strcmp(*argv, "pb"))
	// 	//function for PB
	// if (ft_strcmp(*argv, "ra"))
	// 	//function for RA
	// if (ft_strcmp(*argv, "rb"))
	// 	//function for RB
	// if (ft_strcmp(*argv, "rr"))
	// 	//function for RR
	// if (ft_strcmp(*argv, "rra"))
	// 	//function for RRA
	// if (ft_strcmp(*argv, "rrb"))
	// 	//function for RRB
	// if (ft_strcmp(*argv, "rrr"))
	// 	//function for RRR
}

static int	checker_sort(t_stack *stack)
{
	int		i;
	int		j;

	i = 1;
	j = 2;
	while (stack->next != NULL)
	{
		if (stack->number <= stack->next->number)
			stack = stack->next;
		else
		{
			ft_printf("KO\n");
			exit (0);
		}
	}
	ft_printf("OK\n");
	return (0);
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
			ft_putstr("ERROR\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*new_stack_a;
	int 		i;

	i = 1;
	valid_input(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	while (argv[i])
	{
		new_stack_a = ft_newnode(ft_atoi(argv[i]));
		if (new_stack_a == NULL)
			return (0);
		ft_stackaddback(&stack_a, new_stack_a);
		i++;
	}
	checker_commands(&stack_a, &stack_b);
	test_print(stack_a, stack_b);
	checker_sort(stack_a);
	return (0);
}
