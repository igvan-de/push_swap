/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 15:33:40 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/25 15:45:19 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_input(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
		exit(0);
	while (i < argc)
	{
		argv++;
		if (ft_isnum(*argv) == 0)
		{
			ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
			exit(0);
		}
		i++;
	}
	return (0);
}

static int	double_input(char **argv)
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
	return (0);
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
	double_input(argv);
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
	algorithm(&stack_a, &stack_b, chunk, i - 1);
	exit(0);
}
