/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/18 17:58:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	valid_input(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
		exit(0);
	while (argv[i])
	{
		if (ft_isnum(argv[i]) == 0 && (ft_strequ(argv[i], "-v") == -1
			|| ft_strequ(argv[i], "-c") == -1 || ft_strequ(argv[i], "-i") == -1
			|| ft_strequ(argv[i], "-ic") == -1))
		{
			ft_printf("ERROR\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

static void	line_compare(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa_sb(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		sa_sb(stack_b);
	else if (ft_strcmp(line, "pa") == 0)
		pa_pb(stack_b, stack_a);
	else if (ft_strcmp(line, "pb") == 0)
		pa_pb(stack_a, stack_b);
	else if (ft_strcmp(line, "ra") == 0)
		ra_rb(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		ra_rb(stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		rra_rrb(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		rra_rrb(stack_b);
	else if (ft_strcmp(line, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(stack_a, stack_b);
	else
		ft_printf("Please give a valid operation to execute\n");
}

static void	read_stdin(t_stack *stack_a, t_stack *stack_b, char **argv, int i)
{
	int			count;
	char		*line;

	count = 1;
	line = NULL;
	*argv = argv[i];
	while (get_next_line(0, &line) > 0)//NEED TO FIX GET_NEXT_LINE
	{
		line_compare(line, &stack_a, &stack_b);
		if (ft_strequ(argv[i], "-v") == 1)
			print(stack_a, stack_b);
		if (ft_strequ(argv[i], "-c") == 1)
			color_print(stack_a, stack_b, argv, count);
		if (ft_strequ(argv[i], "-i") == 1)
		{
			color_print(stack_a, stack_b, argv, count);
			count++;
		}
		if (ft_strequ(argv[i], "-ic") == 1)
		{
			color_print(stack_a, stack_b, argv, count);
			count++;
		}
		line = NULL;
		free(line);
	}
}

static void	checker_sort(t_stack *stack)
{
	t_stack	*prob;

	prob = stack;
	while (prob)
	{
		if (prob->next != NULL)
		{
			if (prob->number > prob->next->number)
			{
				ft_printf("KO\n");
				exit(0);
			}
		}
		prob = prob->next;
	}
	ft_printf("OK\n");
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*new_stack_a;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 0)
		return (-1);
	valid_input(argc, argv);
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-v") == 1 || ft_strequ(argv[i], "-c") == 1
			|| ft_strequ(argv[i], "-i") == 1 || ft_strequ(argv[i], "-ic") == 1)
			break ;
		new_stack_a = ft_newnode(ft_atoi(argv[i]));
		if (new_stack_a == NULL)
			return (-1);
		ft_stackaddback(&stack_a, new_stack_a);
		i++;
	}
	read_stdin(stack_a, stack_b, argv, i);
	checker_sort(stack_a);
	return (0);
}
