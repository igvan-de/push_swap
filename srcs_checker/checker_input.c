/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 12:02:21 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/07 14:25:37 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_option(char **argv, int i, t_options *option)
{
	if (ft_strequ(argv[i], "-v") == 1)
		option->flags |= FLAG_V;
	else if (ft_strequ(argv[i], "-c") == 1)
		option->flags |= FLAG_C;
	else if (ft_strequ(argv[i], "-t") == 1)
		option->flags |= FLAG_T;
	else if (ft_strequ(argv[i], "-o") == 1)
		option->flags |= FLAG_O;
	else if (ft_strequ(argv[i], "-i") == 1)
		option->flags |= FLAG_I;
	else if (ft_strequ(argv[i], "-r") == 1)
		option->flags |= FLAG_R;
	else if (ft_strequ(argv[i], "--help"))
		option->flags |= FLAG_HELP;
	else
		return (-1);
	return (0);
}

int			option_input(char **argv, int i, t_options *option)
{
	while (argv[i])
	{
		check_option(argv, i, option);
		if (ft_isnum(argv[i]) == 1)
			break ;
		else if (ft_isnum(argv[i]) == 0 && check_option(argv, i, option) == -1)
		{
			ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
			exit(0);
		}
		i++;
	}
	return (i);
}

void		valid_input(char **argv, int i)
{
	if (ft_isnum(argv[i]) == 0)
	{
		ft_printf(COLOR_BOLD_RED"ERROR\n"COLOR_RESET);
		exit(0);
	}
}

int			double_input(char **argv)
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
