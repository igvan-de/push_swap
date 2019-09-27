/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/27 13:26:47 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	wrong_input(t_options *option)
{
	option->flags |= FLAG_WRONG_INPUT;
	ft_printf("Please give a valid operation to execute\n");
}

static void	stdin_compare(char *line, t_stack **stack_a, t_stack **stack_b,
			t_options *option)
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
		wrong_input(option);
}

static void	checker_sort(t_stack *stack_a, t_stack *stack_b, t_options *option)
{
	t_stack		*prob;

	prob = stack_a;
	while (prob)
	{
		if (prob->next != NULL)
		{
			if (prob->number > prob->next->number)
			{
				if (option->flags & FLAG_R)
					print(stack_a, stack_b);
				ft_printf(COLOR_BOLD_RED"KO\n"COLOR_RESET);
				exit(0);
			}
		}
		prob = prob->next;
	}
	if (option->flags & FLAG_R)
		print(stack_a, stack_b);
	ft_printf(COLOR_BOLD_GREEN"OK\n"COLOR_RESET);
}

static void	read_stdin(t_stack *stack_a, t_stack *stack_b, t_options *option)
{
	char		*line;

	line = NULL;
	option->count = 1;
	while (get_next_line(0, &line) > 0)
	{
		option->flags &= ~FLAG_WRONG_INPUT;
		stdin_compare(line, &stack_a, &stack_b, option);
		option_print(stack_a, stack_b, option, line);
		free(line);
		line = NULL;
		if (!(option->flags & FLAG_WRONG_INPUT))
			option->count++;
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
