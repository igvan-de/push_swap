/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/17 17:40:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			line_compare(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa") == 0)
	{
		ft_printf("sa\n");
		sa_sb(stack_a);
	}
	if (ft_strcmp(line, "sb") == 0)
	{
		ft_printf("sb\n");
		sa_sb(stack_b);
	}
	if (ft_strcmp(line, "pa") == 0)
	{
		ft_printf("pa\n");
		pa_pb(stack_b, stack_a);
	}
	if (ft_strcmp(line, "pb")  == 0)
	{
		ft_printf("pb\n");
		pa_pb(stack_a, stack_b);
	}
	if (ft_strcmp(line, "ra") == 0)
	{
		ft_printf("ra\n");
		ra_rb(stack_a);
	}
	if (ft_strcmp(line, "rb") == 0)
	{
		ft_printf("rb\n");
		ra_rb(stack_b);
	}
	if (ft_strcmp(line, "rra") == 0)
	{
		ft_printf("rra\n");
		rra_rrb(stack_a);
	}
	if (ft_strcmp(line, "rrb") == 0)
	{
		ft_printf("rrb\n");
		rra_rrb(stack_b);
	}
	if (ft_strcmp(line, "ss") == 0)
	{
		ft_printf("ss\n");
		ss(stack_a, stack_b);
	}
	if (ft_strcmp(line, "rr") == 0)
	{
		ft_printf("rr\n");
		rr(stack_a, stack_b);
	}
	if (ft_strcmp(line, "rrr") == 0)
	{
		ft_printf("rrr\n");
		rrr(stack_a, stack_b);
	}
}

static int		valid_input(int argc, char **argv)
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

static void		checker_sort(t_stack *stack)
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
				exit (0);
			}
		}
		prob = prob->next;
	}
	ft_printf("OK\n");
}

int				main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*new_stack_a;
	char		*line;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 0)
		return (0);
	valid_input(argc, argv);
	while (argv[i])
	{
		new_stack_a = ft_newnode(ft_atoi(argv[i]));
		if (new_stack_a == NULL)
			return (-1);
		ft_stackaddback(&stack_a, new_stack_a);
		i++;
	}
	line = NULL;
	while (get_next_line(0, &line) > 0) //NEED TO FIX GET_NEXT_LINE
    {
		line_compare(line, &stack_a, &stack_b);
		line = NULL;
        free(line);
    }
	checker_sort(stack_a);
	return (0);
}
