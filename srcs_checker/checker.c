/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/23 19:42:21 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

static void	checker_sort(t_stack *stack_a, t_stack *stack_b, t_options *option)
{
	t_stack	*prob;

	prob = stack_a;
	while (prob)
	{
		if (prob->next != NULL)
		{
			if (prob->number > prob->next->number)
			{
				if (option->r_argv == 1)
					print(stack_a, stack_b);
				ft_printf(COLOR_BOLD_RED"KO\n"COLOR_RESET);
				exit(0);
			}
		}
		prob = prob->next;
	}
	if (option->r_argv == 1)
		print(stack_a, stack_b);
	ft_printf(COLOR_BOLD_GREEN"OK\n"COLOR_RESET);
}

static void	read_stdin(t_stack *stack_a, t_stack *stack_b, t_options *option)
{
	char		*line;
	int			count;

	count = 1;
	line = NULL;
	while (get_next_line(0, &line) > 0)//NEED TO FIX GET_NEXT_LINE
	{
		line_compare(line, &stack_a, &stack_b);
		special_print((t_stack*[2]){stack_a, stack_b}, option, line, count);
		line = NULL;
		free(line);
		count++;
	}
	checker_sort(stack_a, stack_b, option);
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*new_stack_a;
	t_options	*option;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	option = (t_options*)ft_memalloc(sizeof(t_options));
	i = 1;
	if (argc == 1)
		return (-1);
	i = option_input(argv, i, option);
	double_input(argv);
	while (argv[i])
	{
		valid_input(argv, i);
		new_stack_a = ft_newnode(ft_atoi(argv[i]));
		if (new_stack_a == NULL)
			return (-1);
		ft_stackaddback(&stack_a, new_stack_a);
		i++;
	}
	read_stdin(stack_a, stack_b, option);
	return (0);
}
