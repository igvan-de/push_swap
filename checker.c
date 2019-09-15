/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 12:37:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/15 16:44:56 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			checker_sort(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i + 1] != '\0')
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc == 0)
		return (0);
	fd = open(*argv, O_RDONLY);
	if (checker_sort(argv) == 1)
	{
			ft_printf("KO\n");
			exit (0);
	}
	else
		ft_printf("OK\n");
	return (0);
}
