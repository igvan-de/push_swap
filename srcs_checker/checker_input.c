/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 12:02:21 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/25 15:40:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		option_input(char **argv, int i, t_options *option)
{
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-v") == 1)
			option->v_argv = 1;
		else if (ft_strequ(argv[i], "-c") == 1)
			option->c_argv = 1;
		else if (ft_strequ(argv[i], "-t") == 1)
			option->t_argv = 1;
		else if (ft_strequ(argv[i], "-o") == 1)
			option->o_argv = 1;
		else if (ft_strequ(argv[i], "-i") == 1)
			option->i_argv = 1;
		else if (ft_strequ(argv[i], "-r") == 1)
			option->r_argv = 1;
		else if (ft_isnum(argv[i]) == 1)
			break ;
		else
		{
			ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
			exit(0);
		}
		i++;
	}
	return (i);
}

void	valid_input(char **argv, int i)
{
	if (ft_isnum(argv[i]) == 0)
	{
		ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
		exit(0);
	}
}

int		double_input(char **argv)
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
