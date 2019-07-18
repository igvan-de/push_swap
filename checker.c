/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/07/18 18:00:38 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_commands(char **argv)
{
	if (ft_strcmp(*argv, "sa"))
		//function for SA
	if (ft_strcmp(*argv, "sb"))
		//function for SB
	if (ft_strcmp(*argv, "ss"))
		//function for SS
	if (ft_strcmp(*argv, "pa"))
		//function for PA
	if (ft_strcmp(*argv, "pb"))
		//function for PB
	if (ft_strcmp(*argv, "ra"))
		//function for RA
	if (ft_strcmp(*argv, "rb"))
		//function for RB
	if (ft_strcmp(*argv, "rr"))
		//function for RR
	if (ft_strcmp(*argv, "rra"))
		//function for RRA
	if (ft_strcmp(*argv, "rrb"))
		//function for RRB
	if (ft_strcmp(*argv, "rrr"))
		//function for RRR
}

static int	checker_sort(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 2;
	while (j < argc)
	{
		if (ft_atoi(argv[i]) <= ft_atoi(argv[j]))
		{
			i++;
			if (ft_strcmp(argv[j], "\n") != 0)
				j++;
		}
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
	if (argc < 1)
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
	valid_input(argc, argv);
	checker_sort(argc, argv);
	return (0);
}
