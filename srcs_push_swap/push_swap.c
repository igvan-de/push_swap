/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 15:33:40 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/14 17:51:24 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_input(char **argv)
{
	char	*current;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		current = argv[i];
		j = i;
		while (argv[j])
		{
			j++;
			if (argv[j] == '\0')
				break ;
			if (ft_strcmp(current, argv[j]) == 0)
			{
				ft_printf(COLOR_BOLD_RED"Double input\n"COLOR_RESET);
				exit(0);
			}
		}
		i++;
	}
}

static void	valid_value(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoilong(argv[i]) < MIN_INT || ft_atoilong(argv[i]) > MAX_INT)
		{
			ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
			exit(0);
		}
		i++;
	}
}

static void	valid_input(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
		exit(0);
	if (argc == 2 && ft_isnum(argv[i]) == 1)
		exit(0);
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == 0)
		{
			ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
			exit(0);
		}
		i++;
	}
	double_input(argv);
	is_sorted(argv);
	valid_value(argv);
}

static void	algorithm(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk, int i)
{
	if (i > 10)
		high_value_algorithm(&stack_a, &stack_b, chunk, i - 1);
	else
		low_value_algorithm(&stack_a, &stack_b, i - 1);
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*new_stack_a;
	t_chunk		*chunk;
	int			i;

	i = 1;
	valid_input(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	chunk = (t_chunk*)ft_memalloc(sizeof(t_chunk));
	if (argc == 1)
		return (-1);
	while (argv[i])
	{
		new_stack_a = ft_newnode(ft_atoi(argv[i]));
		if (new_stack_a == NULL)
			return (-1);
		ft_stackaddback(&stack_a, new_stack_a);
		i++;
	}
	algorithm(stack_a, stack_b, chunk, i);
	exit(0);
	return (0);
}
