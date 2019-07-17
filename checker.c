/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/07/17 16:49:54 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	checker(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 1)
		return (0);
	while (i < argc)
	{
		argv++;
		if (ft_isnum(*argv) == 0)
		{
			ft_putstr("ERROR\n");
			return(0);
		}
		i++;

	}
	return (0);
}

int			main(int argc, char **argv)
{
	checker(argc, argv);
	return (0);
}
